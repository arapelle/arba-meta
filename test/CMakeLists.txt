include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        project_version_tests.cpp
        exception_policy_tests.cpp
        thread_policy_tests.cpp
        type_or_tests.cpp
        value_or_tests.cpp
        value_or_generate_tests.cpp
        remove_right_reference_tests.cpp
)
