
add_executable(hash_unit hash_unit_tests.c)
target_link_libraries(hash_unit LINK_PUBLIC hash_static)

add_executable(hash_unit2 hash_unit_tests.c)
target_link_libraries(hash_unit2 LINK_PUBLIC hash_static)

add_executable(hash_unit3 hash_unit_tests.c)
target_link_libraries(hash_unit3 LINK_PUBLIC hash_static)

add_test(unit hash_unit)
add_test(unit2 hash_unit2)
add_test(unit3 hash_unit3)
