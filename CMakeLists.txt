cmake_minimum_required(VERSION 3.18)
project(cpp-best-prac-with-code)

# SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_STANDARD 17)

add_executable(why_weak_ptr why_weak_ptr.cpp)
add_executable(virtual_destructor virtual_destructor.cpp)
add_executable(alignment alignment.cpp)
add_executable(shared_ptr shared_ptr.cpp)
add_executable(inline_func inline_func/inline1.cpp inline_func/inline2.cpp)
add_executable(inline_func_o2 inline_func/inline1.cpp inline_func/inline2.cpp)
target_compile_options(inline_func_o2 PRIVATE "-O2")

