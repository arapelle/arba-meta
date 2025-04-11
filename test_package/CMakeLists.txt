cmake_minimum_required(VERSION 3.15)

project(PackageTest CXX)

set(test_program "test_package")
add_executable(${test_program}
    test_package.cpp
)

set(lib_namespace "arba")
set(lib_feature_name "meta")
find_package(${lib_namespace}-${lib_feature_name} CONFIG REQUIRED)

target_link_libraries(${test_program}
    PRIVATE
        ${lib_namespace}::${lib_feature_name}
)

target_compile_features(${test_program} PRIVATE cxx_std_20)
target_compile_definitions(${test_program} PRIVATE -DARBA_CPPX_VERBOSE_VERSION)
