project(cpp-best-prac-with-code)

# SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_BUILD_TYPE Debug)
SET(CMAKE_CXX_STANDARD 17)

add_executable(shared_ptr shared_ptr.cpp)

# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")
add_executable(smart_ptr_mem_leak smart_ptr_mem_leak.cpp)
add_executable(why_weak_ptr why_weak_ptr.cpp)