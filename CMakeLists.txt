cmake_minimum_required(VERSION 3.26)

# EXTERNAL DEPENDENCIES

add_subdirectory(external)

# CMAKE INCLUDES

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/external/cmake/)
include(CMakePrintHelpers)
include(cmtk/CppLibraryProject)

# CONFIGURATION

disable_in_source_build()
set_build_type_ifndef()

# C++ PROJECT

set_project_name(NAMESPACE "arba" FEATURE_NAME "meta")
string(TIMESTAMP configure_datetime "%Y%m%d-%H%M%S")
set_project_semantic_version("0.6.0" PRE_RELEASE "dev" BUILD_METADATA "${configure_datetime}")

project(${PROJECT_NAME}
        VERSION ${PROJECT_VERSION}
        DESCRIPTION "A C++ library providing meta programming features (policies, type traits, template helpers...)."
        HOMEPAGE_URL "https://github.com/arapelle/arba-meta"
        LANGUAGES CXX)
message(STATUS "PROJECT : ${PROJECT_NAME} ${PROJECT_SEMANTIC_VERSION} ${CMAKE_BUILD_TYPE}")

# C++ LIBRARY

## Generated/Configured headers:
configure_headers(configured_headers
    FILES
        include/${PROJECT_NAMESPACE}/${PROJECT_FEATURE_NAME}/version.hpp.in
)

## Headers:
set(headers
    include/arba/meta/algorithm/concat.hpp
    include/arba/meta/algorithm/filter_and_make_tuple.hpp
    include/arba/meta/concept/addable.hpp
    include/arba/meta/concept/arithmetic.hpp
    include/arba/meta/concept/bitwise_logical.hpp
    include/arba/meta/concept/bitwise_shiftable.hpp
    include/arba/meta/concept/decrementable.hpp
    include/arba/meta/concept/floating_point.hpp
    include/arba/meta/concept/incrementable.hpp
    include/arba/meta/concept/integral.hpp
    include/arba/meta/concept/multipliable.hpp
    include/arba/meta/concept/signedness.hpp
    include/arba/meta/concept/totally_arithmetic.hpp
    include/arba/meta/policy/endianness_policy.hpp
    include/arba/meta/policy/exception_policy.hpp
    include/arba/meta/policy/thread_policy.hpp
    include/arba/meta/type_traits/associated_type.hpp
    include/arba/meta/type_traits/crtp.hpp
    include/arba/meta/type_traits/default.hpp
    include/arba/meta/type_traits/enum.hpp
    include/arba/meta/type_traits/integer_n.hpp
    include/arba/meta/type_traits/integer_sized_string_pack.hpp
    include/arba/meta/type_traits/is_moveable_to_itself.hpp
    include/arba/meta/type_traits/kwargs.hpp
    include/arba/meta/type_traits/make_mutex_type.hpp
    include/arba/meta/type_traits/remove_right_reference.hpp
    include/arba/meta/type_traits/sequence.hpp
    include/arba/meta/type_traits/type_and_source_location.hpp
    include/arba/meta/type_traits/type_or_default.hpp
    include/arba/meta/type_traits/value_or_default.hpp
    include/arba/meta/type_traits/value_or_generate.hpp
)

## Add C++ library:
cxx_standard_option(${PROJECT_UPPER_VAR_NAME}_CXX_STANDARD MIN 20 MAX 26)

add_cpp_library(${PROJECT_NAME} HEADER_ONLY
  HEADERS ${headers} ${configured_headers}
  CXX_STANDARD ${${PROJECT_UPPER_VAR_NAME}_CXX_STANDARD}
  DEFAULT_WARNING_OPTIONS
  DEFAULT_ERROR_OPTIONS
)
add_library("${PROJECT_NAMESPACE}::${PROJECT_FEATURE_NAME}" ALIAS ${PROJECT_NAME})

## Link C++ targets:
find_package(arba-cppx 0.3.0 REQUIRED CONFIG)
target_link_libraries(${PROJECT_NAME}
    INTERFACE
        arba::cppx
)

## Add tests:
add_test_subdirectory_if_build(test)

## Add examples:
add_example_subdirectory_if_build(example)

# C++ INSTALL

## Install C++ library:
install_cpp_libraries(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}-targets)

## Install project package
install_library_package(${PROJECT_NAME} INPUT_PACKAGE_CONFIG_FILE cmake/config/package-config.cmake.in)
install_uninstall_script(${PROJECT_NAME})
