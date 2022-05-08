set(HEADER_FILES ../hash_sources/hash.h)
add_executable(hash_unit hash_unit.c ${HEADER_FILES})

target_link_libraries(hash_unit LINK_PUBLIC hash_static)


add_test(NAME tests_unitaires__one COMMAND ./hash_unit unit)
add_test(NAME tests_unitaires__two COMMAND ./hash_unit NULL)

