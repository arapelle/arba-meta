
add_cpp_library_basic_tests(${PROJECT_NAME} GTest::gtest_main
    SOURCES
        signedness_tests.cpp
        incrementable_tests.cpp
        decrementable_tests.cpp
        addable_tests.cpp
        multipliable_tests.cpp
        bitwise_logical_tests.cpp
        bitwise_shiftable_tests.cpp
        arithmetic_tests.cpp
        totally_arithmetic_tests.cpp
        integral_tests.cpp
        floating_point_tests.cpp
)
