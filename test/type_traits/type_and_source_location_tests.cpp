#include <arba/meta/type_traits/type_and_source_location.hpp>

#include <gtest/gtest.h>

#include <format>
#include <string>
#include <string_view>

TEST(type_and_source_location_tests, constructor__type_lvalue__ok)
{
    std::string input("str");
    // clang-format off
    meta::type_and_source_location<std::string> arg(input); const std::source_location sloc = std::source_location::current();
    // clang-format on
    ASSERT_EQ(input, "str");
    ASSERT_EQ(arg.first, "str");
    ASSERT_EQ(arg.second.file_name(), sloc.file_name());
    ASSERT_EQ(arg.second.line(), sloc.line());
    ASSERT_EQ(arg.second.function_name(), sloc.function_name());
}

TEST(type_and_source_location_tests, constructor__type_rvalue__ok)
{
    std::string input("str");
    // clang-format off
    meta::type_and_source_location<std::string> arg(std::move(input)); const std::source_location sloc = std::source_location::current();
    // clang-format on
    ASSERT_EQ(input, "");
    ASSERT_EQ(arg.first, "str");
    ASSERT_EQ(arg.second.file_name(), sloc.file_name());
    ASSERT_EQ(arg.second.line(), sloc.line());
    ASSERT_EQ(arg.second.function_name(), sloc.function_name());
}

struct custom_string
{
    std::string value;
    custom_string(const std::string& val) : value(val) { value += 'L'; }
    custom_string(std::string&& val) : value(std::forward<std::string>(val)) { value += 'R'; }
    operator std::string_view() const noexcept { return value; }
};

TEST(type_and_source_location_tests, constructor__convertible_lvalue_to_type__ok)
{
    std::string input("str");
    meta::type_and_source_location<custom_string> arg(input);
    ASSERT_EQ(arg.first.value, "strL");
    ASSERT_EQ(input, "str");
}

TEST(type_and_source_location_tests, constructor__convertible_rvalue_to_type__ok)
{
    std::string input("str");
    meta::type_and_source_location<custom_string> arg(std::move(input));
    ASSERT_EQ(arg.first.value, "strR");
    ASSERT_EQ(input, "");
}

template <class... Args>
std::string log_format(meta::type_and_source_location<std::string_view> arg, Args&&... args)
{
    std::string fmt("[{}:{}@{}]: ");
    fmt += arg.first;
    const std::string_view file_name = arg.second.file_name();
    const int line = arg.second.line();
    const std::string_view function_name = arg.second.function_name();
    return std::vformat(fmt, std::make_format_args(file_name, line, function_name, std::forward<Args>(args)...));
}

TEST(type_and_source_location_tests, string_view_with_source_location__implicit_construction_from_c_str__ok)
{
    const int value = 42;
    // clang-format off
    std::string log_str = log_format("value={}", value); const std::source_location sloc = std::source_location::current();
    // clang-format on
    std::string expected_str =
        std::format("[{}:{}@{}]: value={}", sloc.file_name(), sloc.line(), sloc.function_name(), value);
    ASSERT_EQ(log_str, expected_str);
}
