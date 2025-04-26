
add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        simple_base_tests.cpp
        decorated_base_tests.cpp
        base_decorated_with_decorator_tests.cpp
)
