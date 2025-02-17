
#include "ut/nothing.hpp"
#include <arba/meta/concept/bitwise_shiftable.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct bitwise_shiftable_assignable
{
    using self_type = bitwise_shiftable_assignable;
    auto& operator<<=(const self_type&) { return *this; }
    auto& operator>>=(const self_type&) { return *this; }
};

struct bitwise_shiftable
{
    using self_type = bitwise_shiftable;
    auto& operator<<=(const self_type&) { return *this; }
    auto& operator>>=(const self_type&) { return *this; }
    auto operator<<(const self_type&) const { return *this; }
    auto operator>>(const self_type&) const { return *this; }
};
} // namespace ut

TEST(bitwise_shiftable_tests, test_bitwise_shiftable_assignable)
{
    static_assert(meta::BitwiseShiftableAssignable<bool>);
    static_assert(meta::BitwiseShiftableAssignable<char>);
    static_assert(meta::BitwiseShiftableAssignable<int>);
    static_assert(meta::BitwiseShiftableAssignable<unsigned>);
    static_assert(meta::BitwiseShiftableAssignable<int8_t>);
    static_assert(meta::BitwiseShiftableAssignable<int16_t>);
    static_assert(meta::BitwiseShiftableAssignable<int32_t>);
    static_assert(meta::BitwiseShiftableAssignable<int64_t>);
    static_assert(meta::BitwiseShiftableAssignable<intmax_t>);
    static_assert(meta::BitwiseShiftableAssignable<uint8_t>);
    static_assert(meta::BitwiseShiftableAssignable<uint16_t>);
    static_assert(meta::BitwiseShiftableAssignable<uint32_t>);
    static_assert(meta::BitwiseShiftableAssignable<uint64_t>);
    static_assert(meta::BitwiseShiftableAssignable<uintmax_t>);
    static_assert(meta::BitwiseShiftableAssignable<size_t>);
    static_assert(!meta::BitwiseShiftableAssignable<float>);
    static_assert(!meta::BitwiseShiftableAssignable<double>);
    static_assert(meta::BitwiseShiftableAssignable<ut::bitwise_shiftable_assignable>);
    static_assert(meta::BitwiseShiftableAssignable<ut::bitwise_shiftable>);
    static_assert(!meta::BitwiseShiftableAssignable<ut::nothing>);
    SUCCEED();
}

TEST(bitwise_shiftable_tests, test_bitwise_shiftable)
{
    static_assert(meta::BitwiseShiftable<bool>);
    static_assert(meta::BitwiseShiftable<char>);
    static_assert(meta::BitwiseShiftable<int>);
    static_assert(meta::BitwiseShiftable<unsigned>);
    static_assert(meta::BitwiseShiftable<int8_t>);
    static_assert(meta::BitwiseShiftable<int16_t>);
    static_assert(meta::BitwiseShiftable<int32_t>);
    static_assert(meta::BitwiseShiftable<int64_t>);
    static_assert(meta::BitwiseShiftable<intmax_t>);
    static_assert(meta::BitwiseShiftable<uint8_t>);
    static_assert(meta::BitwiseShiftable<uint16_t>);
    static_assert(meta::BitwiseShiftable<uint32_t>);
    static_assert(meta::BitwiseShiftable<uint64_t>);
    static_assert(meta::BitwiseShiftable<uintmax_t>);
    static_assert(meta::BitwiseShiftable<size_t>);
    static_assert(!meta::BitwiseShiftable<float>);
    static_assert(!meta::BitwiseShiftable<double>);
    static_assert(!meta::BitwiseShiftable<ut::bitwise_shiftable_assignable>);
    static_assert(meta::BitwiseShiftable<ut::bitwise_shiftable>);
    static_assert(!meta::BitwiseShiftable<ut::nothing>);
    SUCCEED();
}

namespace ut
{
struct bitwise_shiftable_assignable_with
{
    using self_type = bitwise_shiftable_assignable_with;
    using other_type = unsigned;
    auto& operator<<=(const other_type&) { return *this; }
    auto& operator>>=(const other_type&) { return *this; }
};

struct bitwise_shiftable_with
{
    using self_type = bitwise_shiftable_with;
    auto& operator<<=(const self_type&) { return *this; }
    auto& operator>>=(const self_type&) { return *this; }
    auto operator<<(const self_type&) const { return *this; }
    auto operator>>(const self_type&) const { return *this; }
    using other_type = unsigned;
    auto& operator<<=(const other_type&) { return *this; }
    auto& operator>>=(const other_type&) { return *this; }
    auto operator<<(const other_type&) const { return *this; }
    auto operator>>(const other_type&) const { return *this; }
};
} // namespace ut

TEST(bitwise_shiftable_tests, test_bitwise_shiftable_assignable_with)
{
    using other_type = unsigned;
    static_assert(meta::BitwiseShiftableAssignableWith<bool, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<char, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<int, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<unsigned, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<int8_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<int16_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<int32_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<int64_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<intmax_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<uint8_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<uint16_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<uint32_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<uint64_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<uintmax_t, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<size_t, other_type>);
    static_assert(!meta::BitwiseShiftableAssignableWith<float, other_type>);
    static_assert(!meta::BitwiseShiftableAssignableWith<double, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<ut::bitwise_shiftable_assignable_with, other_type>);
    static_assert(meta::BitwiseShiftableAssignableWith<ut::bitwise_shiftable_with, other_type>);
    static_assert(!meta::BitwiseShiftableAssignableWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(bitwise_shiftable_tests, test_bitwise_shiftable_with)
{
    using other_type = unsigned;
    static_assert(meta::BitwiseShiftableWith<bool, other_type>);
    static_assert(meta::BitwiseShiftableWith<char, other_type>);
    static_assert(meta::BitwiseShiftableWith<int, other_type>);
    static_assert(meta::BitwiseShiftableWith<unsigned, other_type>);
    static_assert(meta::BitwiseShiftableWith<int8_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<int16_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<int32_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<int64_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<intmax_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<uint8_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<uint16_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<uint32_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<uint64_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<uintmax_t, other_type>);
    static_assert(meta::BitwiseShiftableWith<size_t, other_type>);
    static_assert(!meta::BitwiseShiftableWith<float, other_type>);
    static_assert(!meta::BitwiseShiftableWith<double, other_type>);
    static_assert(!meta::BitwiseShiftableWith<ut::bitwise_shiftable_assignable_with, other_type>);
    static_assert(meta::BitwiseShiftableWith<ut::bitwise_shiftable_with, other_type>);
    static_assert(!meta::BitwiseShiftableWith<ut::nothing, other_type>);
    SUCCEED();
}
