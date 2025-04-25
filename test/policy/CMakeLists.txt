
add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        endianness_policy_tests.cpp
        exception_policy_tests.cpp
        thread_policy_tests.cpp
)
