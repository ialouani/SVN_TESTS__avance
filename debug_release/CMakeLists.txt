cmake_minimum_required( VERSION 2.8.11 )


enable_testing()

message(STATUS "build option is set to ${CMAKE_BUILD_TYPE}")


project(foo_debug)





add_subdirectory(hash_sources)
add_subdirectory(tests_niveau__1)

