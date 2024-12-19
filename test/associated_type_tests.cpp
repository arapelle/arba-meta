#include <arba/meta/type_traits/associated_type.hpp>
#include <gtest/gtest.h>

class serializable_tag
{
    ~serializable_tag() = delete;
};

META_DEFINE_ASSOCIATED_TYPE(serializable_tag, std::string, std::u8string)

TEST(associated_type_tests, test_associated_type)
{
    using serializable_string_type = meta::associated_type_t<serializable_tag, std::string>;
    ASSERT_TRUE((std::is_same_v<serializable_string_type, std::u8string>));
}

TEST(associated_type_tests, test_associated_type_or_defined)
{
    using serializable_string_type = meta::associated_type_or_default_t<serializable_tag, std::string, std::u32string>;
    ASSERT_TRUE((std::is_same_v<serializable_string_type, std::u8string>));
    ASSERT_TRUE((!std::is_same_v<serializable_string_type, std::u32string>));
}

TEST(associated_type_tests, test_associated_type_or_undefined)
{
    using serializable_string_type = meta::associated_type_or_default_t<serializable_tag, const char*, std::u32string>;
    ASSERT_TRUE((!std::is_same_v<serializable_string_type, std::u8string>));
    ASSERT_TRUE((std::is_same_v<serializable_string_type, std::u32string>));
}
