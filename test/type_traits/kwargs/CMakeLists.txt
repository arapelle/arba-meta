
add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        kwargs_without_unregognized_args_tests.cpp
        kwargs_with_unregognized_args_tests.cpp
)
