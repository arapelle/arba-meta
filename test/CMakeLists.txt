include(cmtk/CppLibraryTests)
include(GoogleTest)

find_package(GTest 1.14 CONFIG REQUIRED)

add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        project_version_tests.cpp
)

add_subdirectory(algorithm)
add_subdirectory(policy)
add_subdirectory(concepts)
add_subdirectory(type_traits)
