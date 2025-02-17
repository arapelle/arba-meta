
#include "ut/nothing.hpp"
#include <arba/meta/concept/bitwise_logical.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct bitwise_logical_assignable
{
    using self_type = bitwise_logical_assignable;
    auto& operator&=(const self_type&) { return *this; }
    auto& operator|=(const self_type&) { return *this; }
    auto& operator^=(const self_type&) { return *this; }
};

struct bitwise_logical
{
    using self_type = bitwise_logical;
    auto& operator&=(const self_type&) { return *this; }
    auto& operator|=(const self_type&) { return *this; }
    auto& operator^=(const self_type&) { return *this; }
    auto operator&(const self_type&) const { return *this; }
    auto operator|(const self_type&) const { return *this; }
    auto operator^(const self_type&) const { return *this; }
    auto operator~() const { return *this; }
};
} // namespace ut

TEST(bitwise_logical_tests, test_bitwise_logical_assignable)
{
    static_assert(meta::BitwiseLogicalAssignable<bool>);
    static_assert(meta::BitwiseLogicalAssignable<char>);
    static_assert(meta::BitwiseLogicalAssignable<int>);
    static_assert(meta::BitwiseLogicalAssignable<unsigned>);
    static_assert(meta::BitwiseLogicalAssignable<int8_t>);
    static_assert(meta::BitwiseLogicalAssignable<int16_t>);
    static_assert(meta::BitwiseLogicalAssignable<int32_t>);
    static_assert(meta::BitwiseLogicalAssignable<int64_t>);
    static_assert(meta::BitwiseLogicalAssignable<intmax_t>);
    static_assert(meta::BitwiseLogicalAssignable<uint8_t>);
    static_assert(meta::BitwiseLogicalAssignable<uint16_t>);
    static_assert(meta::BitwiseLogicalAssignable<uint32_t>);
    static_assert(meta::BitwiseLogicalAssignable<uint64_t>);
    static_assert(meta::BitwiseLogicalAssignable<uintmax_t>);
    static_assert(meta::BitwiseLogicalAssignable<size_t>);
    static_assert(!meta::BitwiseLogicalAssignable<float>);
    static_assert(!meta::BitwiseLogicalAssignable<double>);
    static_assert(meta::BitwiseLogicalAssignable<ut::bitwise_logical_assignable>);
    static_assert(meta::BitwiseLogicalAssignable<ut::bitwise_logical>);
    static_assert(!meta::BitwiseLogicalAssignable<ut::nothing>);
    SUCCEED();
}

TEST(bitwise_logical_tests, test_bitwise_logical)
{
    static_assert(meta::BitwiseLogical<bool>);
    static_assert(meta::BitwiseLogical<char>);
    static_assert(meta::BitwiseLogical<int>);
    static_assert(meta::BitwiseLogical<unsigned>);
    static_assert(meta::BitwiseLogical<int8_t>);
    static_assert(meta::BitwiseLogical<int16_t>);
    static_assert(meta::BitwiseLogical<int32_t>);
    static_assert(meta::BitwiseLogical<int64_t>);
    static_assert(meta::BitwiseLogical<intmax_t>);
    static_assert(meta::BitwiseLogical<uint8_t>);
    static_assert(meta::BitwiseLogical<uint16_t>);
    static_assert(meta::BitwiseLogical<uint32_t>);
    static_assert(meta::BitwiseLogical<uint64_t>);
    static_assert(meta::BitwiseLogical<uintmax_t>);
    static_assert(meta::BitwiseLogical<size_t>);
    static_assert(!meta::BitwiseLogical<float>);
    static_assert(!meta::BitwiseLogical<double>);
    static_assert(!meta::BitwiseLogical<ut::bitwise_logical_assignable>);
    static_assert(meta::BitwiseLogical<ut::bitwise_logical>);
    static_assert(!meta::BitwiseLogical<ut::nothing>);
    SUCCEED();
}

namespace ut
{
struct bitwise_logical_assignable_with
{
    using self_type = bitwise_logical_assignable_with;
    using other_type = unsigned;
    auto& operator&=(const other_type&) { return *this; }
    auto& operator|=(const other_type&) { return *this; }
    auto& operator^=(const other_type&) { return *this; }
};

struct bitwise_logical_with
{
    using self_type = bitwise_logical_with;
    auto& operator&=(const self_type&) { return *this; }
    auto& operator|=(const self_type&) { return *this; }
    auto& operator^=(const self_type&) { return *this; }
    auto operator&(const self_type&) const { return *this; }
    auto operator|(const self_type&) const { return *this; }
    auto operator^(const self_type&) const { return *this; }
    auto operator~() const { return *this; }
    using other_type = unsigned;
    auto& operator&=(const other_type&) { return *this; }
    auto& operator|=(const other_type&) { return *this; }
    auto& operator^=(const other_type&) { return *this; }
    auto operator&(const other_type&) const { return *this; }
    auto operator|(const other_type&) const { return *this; }
    auto operator^(const other_type&) const { return *this; }
};
} // namespace ut

TEST(bitwise_logical_tests, test_bitwise_logical_assignable_with)
{
    using other_type = unsigned;
    static_assert(meta::BitwiseLogicalAssignableWith<bool, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<char, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<int, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<unsigned, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<int8_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<int16_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<int32_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<int64_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<intmax_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<uint8_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<uint16_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<uint32_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<uint64_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<uintmax_t, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<size_t, other_type>);
    static_assert(!meta::BitwiseLogicalAssignableWith<float, other_type>);
    static_assert(!meta::BitwiseLogicalAssignableWith<double, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<ut::bitwise_logical_assignable_with, other_type>);
    static_assert(meta::BitwiseLogicalAssignableWith<ut::bitwise_logical_with, other_type>);
    static_assert(!meta::BitwiseLogicalAssignableWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(bitwise_logical_tests, test_bitwise_logical_with)
{
    using other_type = unsigned;
    static_assert(meta::BitwiseLogicalWith<bool, other_type>);
    static_assert(meta::BitwiseLogicalWith<char, other_type>);
    static_assert(meta::BitwiseLogicalWith<int, other_type>);
    static_assert(meta::BitwiseLogicalWith<unsigned, other_type>);
    static_assert(meta::BitwiseLogicalWith<int8_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<int16_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<int32_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<int64_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<intmax_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<uint8_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<uint16_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<uint32_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<uint64_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<uintmax_t, other_type>);
    static_assert(meta::BitwiseLogicalWith<size_t, other_type>);
    static_assert(!meta::BitwiseLogicalWith<float, other_type>);
    static_assert(!meta::BitwiseLogicalWith<double, other_type>);
    static_assert(!meta::BitwiseLogicalWith<ut::bitwise_logical_assignable_with, other_type>);
    static_assert(meta::BitwiseLogicalWith<ut::bitwise_logical_with, other_type>);
    static_assert(!meta::BitwiseLogicalWith<ut::nothing, other_type>);
    SUCCEED();
}
