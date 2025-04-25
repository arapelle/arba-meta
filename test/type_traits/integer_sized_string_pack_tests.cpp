#include <arba/meta/type_traits/integer_sized_string_pack.hpp>

#include <gtest/gtest.h>

static_assert(meta::IntegerSizedStringPack64<meta::i8_sstring48_pack>);
static_assert(meta::IntegerSizedStringPack64<meta::u8_sstring48_pack>);
static_assert(meta::IntegerSizedStringPack64<meta::i16_sstring40_pack>);
static_assert(meta::IntegerSizedStringPack64<meta::u16_sstring40_pack>);
static_assert(meta::IntegerSizedStringPack64<meta::i32_sstring24_pack>);
static_assert(meta::IntegerSizedStringPack64<meta::u32_sstring24_pack>);

static_assert(meta::IntegerSizedStringPack128<meta::i8_sstring112_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::u8_sstring112_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::i16_sstring104_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::u16_sstring104_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::i32_sstring88_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::u32_sstring88_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::i64_sstring56_pack>);
static_assert(meta::IntegerSizedStringPack128<meta::u64_sstring56_pack>);

TEST(integer_sized_string_pack_tests, test_construtor__no_arg__ok)
{
    const meta::integer_sized_string_pack<unsigned, 8, 48> var;
    ASSERT_EQ(var.integer(), 0);
    ASSERT_EQ(var.string(), "");
}

TEST(integer_sized_string_pack_tests, test_)
{
    const meta::integer_sized_string_pack<unsigned, 8, 48> var(7, std::string_view("SEPT"));
    ASSERT_EQ(var.integer(), 7);
    ASSERT_EQ(var.string(), "SEPT");
    const meta::integer_sized_string_pack<unsigned, 8, 48> var2(0, std::string_view("ORANGES"));
    ASSERT_EQ(var2.integer(), 0);
    ASSERT_EQ(var2.string(), "ORANGE");

    ASSERT_EQ(var, var);
    ASSERT_NE(var, var2);
}

TEST(integer_sized_string_pack_tests, test_2)
{
    const meta::integer_sized_string_pack<unsigned, 8, 48> var(7, "SEPT");
    ASSERT_EQ(var.integer(), 7);
    ASSERT_EQ(var.string(), "SEPT");
    const meta::integer_sized_string_pack<unsigned, 8, 48> var2(0, "ORANGE");
    ASSERT_EQ(var2.integer(), 0);
    ASSERT_EQ(var2.string(), "ORANGE");
}

TEST(integer_sized_string_pack_tests, constexpr_test_construtor__no_arg__ok)
{
    constexpr meta::integer_sized_string_pack<unsigned, 8, 48> var;
    static_assert(var.integer() == 0);
    static_assert(var.string() == "");
}

TEST(integer_sized_string_pack_tests, constexpr_test_)
{
    constexpr meta::integer_sized_string_pack<unsigned, 8, 48> var(7, std::string_view("SEPT"));
    static_assert(var.integer() == 7);
    static_assert(var.string() == "SEPT");
    constexpr meta::integer_sized_string_pack<unsigned, 8, 48> var2(0, std::string_view("ORANGES"));
    static_assert(var2.integer() == 0);
    static_assert(var2.string() == "ORANGE");
}

TEST(integer_sized_string_pack_tests, constexpr_test_2)
{
    constexpr meta::integer_sized_string_pack<unsigned, 8, 48> var(7, "SEPT");
    static_assert(var.integer() == 7);
    static_assert(var.string() == "SEPT");
    constexpr meta::integer_sized_string_pack<unsigned, 8, 48> var2(0, "ORANGE");
    static_assert(var2.integer() == 0);
    static_assert(var2.string() == "ORANGE");
}
