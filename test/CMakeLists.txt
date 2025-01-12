include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        project_version_tests.cpp
        associated_type_tests.cpp
        exception_policy_tests.cpp
        thread_policy_tests.cpp
        type_or_tests.cpp
        value_or_tests.cpp
        value_or_generate_tests.cpp
        remove_right_reference_tests.cpp
        is_moveable_to_itself_tests.cpp
        integer_n_tests.cpp
        make_mutex_type_tests.cpp
        sequence_tests.cpp
)
