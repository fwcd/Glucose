#ifndef GLUCOSE_STREAM_HPP
#define GLUCOSE_STREAM_HPP

#include <vector>
#include <utility>
#include <initializer_list>
#include <functional>

#include "Optional.hpp"
#include "StreamException.hpp"

namespace glucose {

/**
 * A lazily evaluated, temporary sequence
 * of operations on a vector inspired by
 * the Java 8 Streams API.
 * 
 * Every operation will produce a object
 * and disable the current stream (thus
 * throwing an exception when trying to
 * invoke a stream object more than once).
 */
template <typename I, typename O = I> class Stream {
private:
	bool active;
	int index;
	std::vector<I> elements;
	// TODO: Rearchitect pipeline to not require copying on each operation
	std::function<std::vector<O>(std::vector<I>)> pipeline;
public:
	/** Constructs new intermediate stream */
	Stream(const std::vector<I>& elements, std::function<std::vector<O>(std::vector<I>)> pipeline) :
			elements(std::move(elements)),
			pipeline(pipeline),
			active(true),
			index(0) {}
	
	/** Constructs an empty stream */
	Stream() :
			active(true),
			pipeline([] (std::vector<I> input) { return input; }),
			index(0) {}
	
	/** Constructs a stream using the given items */
	Stream(std::initializer_list<I> items) :
			active(true),
			elements(items),
			pipeline([] (std::vector<I> input) { return input; }),
			index(0) {}
	
	/** Constructs a stream using the given vector */
	Stream(std::vector<I> items) :
			elements(items),
			active(true),
			pipeline([] (std::vector<I> input) { return input; }),
			index(0) {}
	
	virtual ~Stream() {}
	
	/** The amount of items in this stream */
	int size() const { return elements.size(); }
	
	/**
	 * Maps this stream to Optionals, then filtering only the present ones
	 * 
	 * This is an intermediate operation which mutates and returns this stream.
	 */
	template <typename R> Stream<I, R> filterMap(std::function<Optional<R>(O)> mapper) {
		assertActive();
		disable();
		return Stream<I, R>(getInputElements(), [this, mapper] (std::vector<I> input) {
			std::vector<O> upstream(getPipeline()(input));
			std::vector<R> downstream;
			for (auto& value : upstream) {
				Optional<R> opt = mapper(value);
				if (opt.isPresent()) {
					downstream.push_back(*opt);
				}
			}
			return downstream;
		});
	}
	
	/**
	 * Applies a transformation to the elements in this stream
	 * 
	 * This is an intermediate operation which mutates and returns this stream.
	 */
	template <typename R> Stream<I, R> map(std::function<R(O)> mapper) {
		assertActive();
		disable();
		Stream<I, R> str(getInputElements(), [this, mapper] (std::vector<I> input) {
			std::vector<O> upstream(getPipeline()(input));
			std::vector<R> downstream;
			for (auto& value : upstream) {
				downstream.push_back(mapper(value));
			}
			return downstream;
		});
		return str;
	}
	
	/**
	 * Filters all elements in this stream that match the given predicate.
	 * 
	 * This is an intermediate operation which mutates and returns this stream.
	 */
	Stream<I, O> filter(std::function<bool(O)> includer) {
		assertActive();
		disable();
		return Stream<I, O>(getInputElements(), [this, includer] (std::vector<I> input) {
			std::vector<O> upstream(getPipeline()(input));
			std::vector<O> downstream;
			for (auto& value : upstream) {
				if (includer(value)) {
					downstream.push_back(value);
				}
			}
			return downstream;
		});
	}
	
	/**
	 * Reduces (or "folds") this stream using an associative accumulator.
	 * 
	 * This is a terminal operation which collapses this stream
	 * into an inaccesible state.
	 */
	O reduce(std::function<O(O, O)> accumulator) {
		assertActive();
		disable();
		std::vector<O> output(pipeline(input));
		O accumulated = output.back();
		output.pop_back();
		for (auto& outputItem : output) {
			accumulated = accumulator(accumulated, outputItem);
		}
		return accumulated;
	}
	
	/**
	 * Collects all resulting elements in a vector.
	 * 
	 * This is a terminal operation which collapses this stream
	 * into an inaccesible state.
	 */
	std::vector<O> toVector() {
		assertActive();
		disable();
		return pipeline(elements);
	}
	
	void assertActive() {
		if (!active) throw StreamException("Tried to access an inactive stream!");
	}
	
	std::function<std::vector<O>(std::vector<I>)> getPipeline() { return pipeline; }
	
	std::vector<I> getInputElements() { return elements; }
	
	/** Disables all operations on this stream */
	void disable() { active = false; }
};

}

#endif // GLUCOSE_STREAM_HPP
