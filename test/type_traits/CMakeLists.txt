
add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        associated_type_tests.cpp
        type_or_tests.cpp
        value_or_tests.cpp
        value_or_generate_tests.cpp
        remove_right_reference_tests.cpp
        is_moveable_to_itself_tests.cpp
        integer_n_tests.cpp
        make_mutex_type_tests.cpp
        sequence_tests.cpp
        type_and_source_location_tests.cpp
        integer_sized_string_pack_tests.cpp
)

add_subdirectory(enum)
