#include <arba/meta/type_traits/associated_type.hpp>

#include <gtest/gtest.h>

class pair_tag;

META_ASSOCIATE_TYPES(pair_tag, std::string, (std::pair<std::string, std::string>));

using pair_string_t = std::pair<std::string, std::string>;
using pair_int_t = std::pair<int, int>;

TEST(associated_type_tests, test_associated_type)
{
    using pair_t = meta::associated_type_t<pair_tag, std::string>;
    static_assert(std::is_same_v<pair_t, pair_string_t>);
}

TEST(associated_type_tests, test_associated_type_or_defined)
{
    using pair_t = meta::associated_type_or_default_t<pair_tag, std::string, pair_int_t>;
    static_assert(std::is_same_v<pair_t, pair_string_t>);
    static_assert(!std::is_same_v<pair_t, pair_int_t>);
}

TEST(associated_type_tests, test_associated_type_or_undefined)
{
    using pair_t = meta::associated_type_or_default_t<pair_tag, const char*, pair_int_t>;
    static_assert(!std::is_same_v<pair_t, pair_string_t>);
    static_assert(std::is_same_v<pair_t, pair_int_t>);
}
