#include "default_arg.hpp"

#include <arba/meta/type_traits/value_or_default.hpp>
#include <format>
#include <gtest/gtest.h>
#include <string>

template <class ValueType, class OptionType>
std::string tfunc(const ValueType& input_value, OptionType& input_option)
{
    decltype(auto) value(meta::value_or_default(input_value, default_arg()));
    decltype(auto) option(meta::value_or_default(input_option, default_arg()));
    std::string value_prefix = "D";
    std::string option_prefix = "D";

    if constexpr (!std::is_same_v<std::remove_cvref_t<ValueType>, meta::default_t>)
    {
        value_prefix = "V";
        static_assert(std::is_same_v<decltype(value), const int&>);
    }
    else
    {
        static_assert(std::is_same_v<decltype(value), default_arg>);
    }

    if constexpr (!std::is_same_v<std::remove_cvref_t<OptionType>, meta::default_t>)
    {
        option_prefix = "V";
        option += 1;
        static_assert(std::is_same_v<decltype(option), int&>);
    }
    else
    {
        static_assert(std::is_same_v<decltype(value), default_arg>);
    }

    return std::format("{}{} {}{}", value_prefix, static_cast<int>(value), option_prefix, static_cast<int>(option));
}

TEST(value_or_tests, test_value_or__default_default__ok)
{
    default_arg::destructor_counter() = 0;
    ASSERT_EQ(tfunc(meta::default_v, meta::default_v), "D1000 D1000");
    ASSERT_EQ(default_arg::destructor_counter(), 2);
}

TEST(value_or_tests, test_value_or__default_int__ok)
{
    default_arg::destructor_counter() = 0;
    int option = 100;
    ASSERT_EQ(tfunc(meta::default_v, option), "D1000 V101");
    ASSERT_EQ(option, 101);
    ASSERT_EQ(default_arg::destructor_counter(), 2);
}

TEST(value_or_tests, test_value_or__int_int__ok)
{
    default_arg::destructor_counter() = 0;
    int option = 100;
    ASSERT_EQ(tfunc(200, option), "V200 V101");
    ASSERT_EQ(option, 101);
    ASSERT_EQ(default_arg::destructor_counter(), 2);
}
