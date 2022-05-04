cmake_minimum_required(VERSION 2.8.11)
project(foo)
add_executable(foo example.c hash.c)
if(CMAKE_COMPILER_IS_GNUCXX)
LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules")
include(CodeCoverage)
APPEND_COVERAGE_COMPILER_FLAGS()
SETUP_TARGET_FOR_COVERAGE_LCOV(NAME foo_coverage
                              EXECUTABLE foo
                              DEPENDENCIES foo)
endif()
