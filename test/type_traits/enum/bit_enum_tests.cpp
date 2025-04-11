#include <arba/meta/type_traits/enum.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <array>

class Rights;

class Right : public meta::enumerator<uint8_t, Rights, meta::enum_conversion::explicit_conversion>
{
private:
    using base_ = meta::enumerator<uint8_t, Rights, meta::enum_conversion::explicit_conversion>;

public:
    constexpr Right() {}
    consteval Right(const base_& val) : base_(val) {}
};

class Rights : public meta::enumeration<Right, Rights>
{
public:
    static constexpr Right read = make_enumerator(1);
    static constexpr Right write = make_enumerator(2);
    static constexpr Right exec = make_enumerator(4);

    static constexpr std::array enumerator_names = { "read", "write", "exec" };
    static constexpr std::array enumerators{ read, write, exec };

    static constexpr bool has_bitwise_index() noexcept { return true; }
};

// ------

TEST(bit_enum_tests, rights__static_assertions__valid)
{
    static_assert(std::is_same_v<Right::value_type, uint8_t>);
    static_assert(!std::constructible_from<Right, uint8_t>);
    static_assert(std::constructible_from<Right, Right>);
    static_assert(std::is_same_v<Right::enumeration, Rights>);
    static_assert(std::is_same_v<Rights::enumerator, Right>);
    static_assert(!Right::implicit);
    static_assert(std::is_same_v<Right::base_type, Right::value_type>);
    static_assert(std::totally_ordered<Right>);
    static_assert(!std::totally_ordered_with<Right, int>);
    static_assert(Rights::enumerator_index_offset() == 1);
}

TEST(bit_enum_tests, rights__construction__ok)
{
    Right right;
    right = Rights::write;
    ASSERT_EQ(right, Rights::write);
    ASSERT_EQ(right.value(), 2);
    ASSERT_EQ(right.name(), "write");
}

TEST(bit_enum_tests, constexpr_rights__construction__ok)
{
    constexpr Right color = Rights::read;
    ASSERT_EQ(color, Rights::read);
    ASSERT_EQ(color.value(), 1);
    ASSERT_EQ(color.name(), "read");
    static_assert(color == Rights::read);
    static_assert(color.value() == 1);
    //    static_assert(color.name() == "read");
}

TEST(bit_enum_tests, rights__value__ok)
{
    ASSERT_EQ(Rights::read.value(), 1);
    ASSERT_EQ(Rights::write.value(), 2);
    ASSERT_EQ(Rights::exec.value(), 4);
}

TEST(bit_enum_tests, constexpr_primary_colors__value__ok)
{
    static_assert(Rights::read.value() == 1);
    static_assert(Rights::write.value() == 2);
    static_assert(Rights::exec.value() == 4);
}

TEST(bit_enum_tests, rights__index__ok)
{
    ASSERT_EQ(Rights::read.index(), 0);
    ASSERT_EQ(Rights::write.index(), 1);
    ASSERT_EQ(Rights::exec.index(), 2);
}

TEST(bit_enum_tests, constexpr_rights__index__ok)
{
    static_assert(Rights::read.index() == 0);
    static_assert(Rights::write.index() == 1);
    static_assert(Rights::exec.index() == 2);
}

TEST(bit_enum_tests, rights__name__ok)
{
    ASSERT_EQ(Rights::read.name(), "read");
    ASSERT_EQ(Rights::write.name(), "write");
    ASSERT_EQ(Rights::exec.name(), "exec");
}

//TEST(bit_enum_tests, constexpr_rights__name__ok)
//{
//    static_assert(Rights::read.name() == "read");
//    static_assert(Rights::write.name() == "write");
//    static_assert(Rights::exec.name() == "exec");
//}

TEST(bit_enum_tests, rights__enumeration_size__ok)
{
    ASSERT_EQ(Rights::size(), 3);
    static_assert(Rights::size() == 3);
}

TEST(bit_enum_tests, rights__all__ok)
{
    ASSERT_EQ(Rights::all(), Rights::enumerators);
    static_assert(Rights::all() == Rights::enumerators);
}

TEST(bit_enum_tests, rights__explicit_conversion__ok)
{
    static_assert(!std::convertible_to<Right, int>);
    const uint8_t exec_value = static_cast<uint8_t>(Rights::exec);
    ASSERT_EQ(exec_value, 4);
}

TEST(bit_enum_tests, rights__hash__ok)
{
    std::hash<Right> enumerator_hasher;
    std::hash<Right::value_type> value_hasher;
    ASSERT_EQ(enumerator_hasher(Rights::read), value_hasher(Rights::read.value()));
}

TEST(bit_enum_tests, rights__format__ok)
{
    ASSERT_EQ(std::format("{}", Rights::read), "read");
    ASSERT_EQ(std::format("{:v}", Rights::write), "2");
    ASSERT_EQ(std::format("{:f}", Rights::exec), "(exec=4)");
}
