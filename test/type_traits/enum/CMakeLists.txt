
add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        string_enum_tests.cpp
        integer_enum_tests.cpp
        integer_string_enum_tests.cpp
        bit_enum_tests.cpp
)
