#include <arba/meta/algorithm/concat.hpp>

#include <gtest/gtest.h>

TEST(concat_tests, concat__int_arrays__ok)
{
    const std::array<int, 3> first_arr = { 3, 3, 3 };
    const std::array<int, 2> second_arr = { 2, 2 };
    const std::array<int, 5> res_arr = meta::concat(first_arr, second_arr);
    ASSERT_EQ(res_arr, (std::array<int, 5>{ 3, 3, 3, 2, 2 }));
}

TEST(concat_tests, constexpr_concat__int_arrays__ok)
{
    constexpr std::array<int, 3> first_arr = { 3, 3, 3 };
    constexpr std::array<int, 2> second_arr = { 2, 2 };
    constexpr std::array<int, 5> res_arr = meta::concat(first_arr, second_arr);
    ASSERT_EQ(res_arr, (std::array<int, 5>{ 3, 3, 3, 2, 2 }));
}

TEST(concat_tests, concat__int_array_and_double_array_to_int_array__ok)
{
    const std::array<int, 3> first_arr = { 3, 3, 3 };
    const std::array<double, 2> second_arr = { 2., 2. };
    const std::array<int, 5> res_arr = meta::concat<int>(first_arr, second_arr);
    ASSERT_EQ(res_arr, (std::array<int, 5>{ 3, 3, 3, 2, 2 }));
}

TEST(concat_tests, concat__int_array_and_double_array_to_double_array__ok)
{
    const std::array<int, 3> first_arr = { 3, 3, 3 };
    const std::array<double, 2> second_arr = { 2., 2. };
    const std::array<double, 5> res_arr = meta::concat<double>(first_arr, second_arr);
    ASSERT_EQ(res_arr, (std::array<double, 5>{ 3, 3, 3, 2, 2 }));
}

TEST(concat_tests, constexpr_concat__int_array_and_double_array_to_int_array__ok)
{
    constexpr std::array<int, 3> first_arr = { 3, 3, 3 };
    constexpr std::array<double, 2> second_arr = { 2., 2. };
    constexpr std::array<int, 5> res_arr = meta::concat<int>(first_arr, second_arr);
    ASSERT_EQ(res_arr, (std::array<int, 5>{ 3, 3, 3, 2, 2 }));
}

TEST(concat_tests, constexpr_concat__int_array_and_double_array_to_double_array__ok)
{
    constexpr std::array<int, 3> first_arr = { 3, 3, 3 };
    constexpr std::array<double, 2> second_arr = { 2., 2. };
    constexpr std::array<double, 5> res_arr = meta::concat<double>(first_arr, second_arr);
    ASSERT_EQ(res_arr, (std::array<double, 5>{ 3., 3., 3., 2., 2. }));
}
