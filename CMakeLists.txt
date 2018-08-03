cmake_minimum_required(VERSION 2.6)
project(Glucose)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(src)

add_executable(GlucoseTest src/test/tests.cpp)
target_link_libraries(GlucoseTest Glucose)
target_link_libraries(GlucoseTest GlucoseTests)
set_target_properties(GlucoseTest PROPERTIES OUTPUT_NAME "glucosetest")

target_include_directories(Glucose PUBLIC include)
target_include_directories(GlucoseTests PRIVATE include)
