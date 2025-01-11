#include <arba/meta/type_traits/type_or_default.hpp>

#include <gtest/gtest.h>

#include <format>
#include <string>

template <class NumberType, class OptionType>
class tclass
{
public:
    using number_type = meta::type_or_default_t<NumberType, int>;
    using option_type = meta::type_or_default_t<OptionType, void>;
};

TEST(type_or_tests, test_type_or_t__unsigned_string__ok)
{
    using tclass_t = tclass<unsigned, std::string>;
    ASSERT_TRUE((std::is_same_v<tclass_t::number_type, unsigned>));
    ASSERT_TRUE((std::is_same_v<tclass_t::option_type, std::string>));
}

TEST(type_or_tests, test_type_or_t__default_string__ok)
{
    using tclass_t = tclass<meta::default_t, std::string>;
    ASSERT_TRUE((std::is_same_v<tclass_t::number_type, int>));
    ASSERT_TRUE((std::is_same_v<tclass_t::option_type, std::string>));
}

TEST(type_or_tests, test_type_or_t__unsigned_default__ok)
{
    using tclass_t = tclass<unsigned, meta::default_t>;
    ASSERT_TRUE((std::is_same_v<tclass_t::number_type, unsigned>));
    ASSERT_TRUE((std::is_same_v<tclass_t::option_type, void>));
}

TEST(type_or_tests, test_type_or_t__default_default__ok)
{
    using tclass_t = tclass<meta::default_t, meta::default_t>;
    ASSERT_TRUE((std::is_same_v<tclass_t::number_type, int>));
    ASSERT_TRUE((std::is_same_v<tclass_t::option_type, void>));
}
