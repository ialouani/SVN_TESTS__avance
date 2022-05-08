add_library(hash_static STATIC hash.c)
target_include_directories(hash_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hash_sources)

