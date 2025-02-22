
#include "ut/nothing.hpp"
#include <arba/meta/concept/addable.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct additive_assignable
{
    using self_type = additive_assignable;
    auto& operator+=(const self_type&) { return *this; }
    auto& operator-=(const self_type&) { return *this; }
};

struct addable
{
    using self_type = addable;
    auto& operator--() { return *this; }
    auto& operator++() { return *this; }
    auto operator--(int) { return *this; }
    auto operator++(int) { return *this; }
    auto& operator+=(const self_type&) { return *this; }
    auto& operator-=(const self_type&) { return *this; }
    auto operator+(const self_type&) const { return *this; }
    auto operator-(const self_type&) const { return *this; }
    auto operator-() const { return *this; }
};
} // namespace ut

TEST(addable_tests, test_additive_assignable)
{
    static_assert(meta::AdditiveAssignable<bool>);
    static_assert(meta::AdditiveAssignable<char>);
    static_assert(meta::AdditiveAssignable<int>);
    static_assert(meta::AdditiveAssignable<unsigned>);
    static_assert(meta::AdditiveAssignable<int8_t>);
    static_assert(meta::AdditiveAssignable<int16_t>);
    static_assert(meta::AdditiveAssignable<int32_t>);
    static_assert(meta::AdditiveAssignable<int64_t>);
    static_assert(meta::AdditiveAssignable<intmax_t>);
    static_assert(meta::AdditiveAssignable<uint8_t>);
    static_assert(meta::AdditiveAssignable<uint16_t>);
    static_assert(meta::AdditiveAssignable<uint32_t>);
    static_assert(meta::AdditiveAssignable<uint64_t>);
    static_assert(meta::AdditiveAssignable<uintmax_t>);
    static_assert(meta::AdditiveAssignable<size_t>);
    static_assert(meta::AdditiveAssignable<float>);
    static_assert(meta::AdditiveAssignable<double>);
    static_assert(meta::AdditiveAssignable<ut::additive_assignable>);
    static_assert(meta::AdditiveAssignable<ut::addable>);
    static_assert(!meta::AdditiveAssignable<ut::nothing>);
    SUCCEED();
}

TEST(addable_tests, test_addable)
{
    static_assert(meta::Addable<bool>);
    static_assert(meta::Addable<char>);
    static_assert(meta::Addable<int>);
    static_assert(meta::Addable<unsigned>);
    static_assert(meta::Addable<int8_t>);
    static_assert(meta::Addable<int16_t>);
    static_assert(meta::Addable<int32_t>);
    static_assert(meta::Addable<int64_t>);
    static_assert(meta::Addable<intmax_t>);
    static_assert(meta::Addable<uint8_t>);
    static_assert(meta::Addable<uint16_t>);
    static_assert(meta::Addable<uint32_t>);
    static_assert(meta::Addable<uint64_t>);
    static_assert(meta::Addable<uintmax_t>);
    static_assert(meta::Addable<size_t>);
    static_assert(meta::Addable<float>);
    static_assert(meta::Addable<double>);
    static_assert(!meta::Addable<ut::additive_assignable>);
    static_assert(meta::Addable<ut::addable>);
    static_assert(!meta::Addable<ut::nothing>);
    SUCCEED();
}

namespace ut
{
struct additive_assignable_with
{
    using self_type = additive_assignable_with;
    using other_type = unsigned;
    auto& operator+=(const other_type&) { return *this; }
    auto& operator-=(const other_type&) { return *this; }
};

struct addable_with
{
    using self_type = addable_with;
    auto& operator--() { return *this; }
    auto& operator++() { return *this; }
    auto operator--(int) { return *this; }
    auto operator++(int) { return *this; }
    auto& operator+=(const self_type&) { return *this; }
    auto& operator-=(const self_type&) { return *this; }
    auto operator+(const self_type&) const { return *this; }
    auto operator-(const self_type&) const { return *this; }
    auto operator-() const { return *this; }
    using other_type = unsigned;
    auto& operator+=(const other_type&) { return *this; }
    auto& operator-=(const other_type&) { return *this; }
    auto operator+(const other_type&) const { return *this; }
    auto operator-(const other_type&) const { return *this; }
};
} // namespace ut

TEST(addable_tests, test_additive_assignable_with)
{
    using other_type = unsigned;
    static_assert(meta::AdditiveAssignableWith<bool, other_type>);
    static_assert(meta::AdditiveAssignableWith<char, other_type>);
    static_assert(meta::AdditiveAssignableWith<int, other_type>);
    static_assert(meta::AdditiveAssignableWith<unsigned, other_type>);
    static_assert(meta::AdditiveAssignableWith<int8_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<int16_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<int32_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<int64_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<intmax_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<uint8_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<uint16_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<uint32_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<uint64_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<uintmax_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<size_t, other_type>);
    static_assert(meta::AdditiveAssignableWith<float, other_type>);
    static_assert(meta::AdditiveAssignableWith<double, other_type>);
    static_assert(meta::AdditiveAssignableWith<ut::additive_assignable_with, other_type>);
    static_assert(meta::AdditiveAssignableWith<ut::addable_with, other_type>);
    static_assert(!meta::AdditiveAssignableWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(addable_tests, test_addable_with)
{
    using other_type = unsigned;
    static_assert(meta::AddableWith<bool, other_type>);
    static_assert(meta::AddableWith<char, other_type>);
    static_assert(meta::AddableWith<int, other_type>);
    static_assert(meta::AddableWith<unsigned, other_type>);
    static_assert(meta::AddableWith<int8_t, other_type>);
    static_assert(meta::AddableWith<int16_t, other_type>);
    static_assert(meta::AddableWith<int32_t, other_type>);
    static_assert(meta::AddableWith<int64_t, other_type>);
    static_assert(meta::AddableWith<intmax_t, other_type>);
    static_assert(meta::AddableWith<uint8_t, other_type>);
    static_assert(meta::AddableWith<uint16_t, other_type>);
    static_assert(meta::AddableWith<uint32_t, other_type>);
    static_assert(meta::AddableWith<uint64_t, other_type>);
    static_assert(meta::AddableWith<uintmax_t, other_type>);
    static_assert(meta::AddableWith<size_t, other_type>);
    static_assert(meta::AddableWith<float, other_type>);
    static_assert(meta::AddableWith<double, other_type>);
    static_assert(!meta::AddableWith<ut::additive_assignable_with, other_type>);
    static_assert(meta::AddableWith<ut::addable_with, other_type>);
    static_assert(!meta::AddableWith<ut::nothing, other_type>);
    SUCCEED();
}
