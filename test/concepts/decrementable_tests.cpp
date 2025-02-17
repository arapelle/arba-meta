
#include "ut/nothing.hpp"
#include <arba/meta/concept/decrementable.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct pre_decrementable
{
    using self_type = pre_decrementable;
    auto& operator--() { return *this; }
};

struct post_decrementable
{
    using self_type = post_decrementable;
    auto operator--(int) { return *this; }
};

struct decrementable
{
    using self_type = decrementable;
    auto& operator--() { return *this; }
    auto operator--(int) { return *this; }
};
} // namespace ut

TEST(decrementable_tests, test_pre_decrementable)
{
    static_assert(meta::PreDecrementable<bool>);
    static_assert(meta::PreDecrementable<char>);
    static_assert(meta::PreDecrementable<int>);
    static_assert(meta::PreDecrementable<unsigned>);
    static_assert(meta::PreDecrementable<int8_t>);
    static_assert(meta::PreDecrementable<int16_t>);
    static_assert(meta::PreDecrementable<int32_t>);
    static_assert(meta::PreDecrementable<int64_t>);
    static_assert(meta::PreDecrementable<intmax_t>);
    static_assert(meta::PreDecrementable<uint8_t>);
    static_assert(meta::PreDecrementable<uint16_t>);
    static_assert(meta::PreDecrementable<uint32_t>);
    static_assert(meta::PreDecrementable<uint64_t>);
    static_assert(meta::PreDecrementable<uintmax_t>);
    static_assert(meta::PreDecrementable<size_t>);
    static_assert(meta::PreDecrementable<float>);
    static_assert(meta::PreDecrementable<double>);
    static_assert(meta::PreDecrementable<ut::pre_decrementable>);
    static_assert(!meta::PreDecrementable<ut::post_decrementable>);
    static_assert(meta::PreDecrementable<ut::decrementable>);
    static_assert(!meta::PreDecrementable<ut::nothing>);
    SUCCEED();
}

TEST(decrementable_tests, test_post_decrementable)
{
    static_assert(meta::PostDecrementable<bool>);
    static_assert(meta::PostDecrementable<char>);
    static_assert(meta::PostDecrementable<int>);
    static_assert(meta::PostDecrementable<unsigned>);
    static_assert(meta::PostDecrementable<int8_t>);
    static_assert(meta::PostDecrementable<int16_t>);
    static_assert(meta::PostDecrementable<int32_t>);
    static_assert(meta::PostDecrementable<int64_t>);
    static_assert(meta::PostDecrementable<intmax_t>);
    static_assert(meta::PostDecrementable<uint8_t>);
    static_assert(meta::PostDecrementable<uint16_t>);
    static_assert(meta::PostDecrementable<uint32_t>);
    static_assert(meta::PostDecrementable<uint64_t>);
    static_assert(meta::PostDecrementable<uintmax_t>);
    static_assert(meta::PostDecrementable<size_t>);
    static_assert(meta::PostDecrementable<float>);
    static_assert(meta::PostDecrementable<double>);
    static_assert(!meta::PostDecrementable<ut::pre_decrementable>);
    static_assert(meta::PostDecrementable<ut::post_decrementable>);
    static_assert(meta::PostDecrementable<ut::decrementable>);
    static_assert(!meta::PostDecrementable<ut::nothing>);
    SUCCEED();
}

TEST(decrementable_tests, test_decrementable)
{
    static_assert(meta::Decrementable<bool>);
    static_assert(meta::Decrementable<char>);
    static_assert(meta::Decrementable<int>);
    static_assert(meta::Decrementable<unsigned>);
    static_assert(meta::Decrementable<int8_t>);
    static_assert(meta::Decrementable<int16_t>);
    static_assert(meta::Decrementable<int32_t>);
    static_assert(meta::Decrementable<int64_t>);
    static_assert(meta::Decrementable<intmax_t>);
    static_assert(meta::Decrementable<uint8_t>);
    static_assert(meta::Decrementable<uint16_t>);
    static_assert(meta::Decrementable<uint32_t>);
    static_assert(meta::Decrementable<uint64_t>);
    static_assert(meta::Decrementable<uintmax_t>);
    static_assert(meta::Decrementable<size_t>);
    static_assert(meta::Decrementable<float>);
    static_assert(meta::Decrementable<double>);
    static_assert(!meta::Decrementable<ut::pre_decrementable>);
    static_assert(!meta::Decrementable<ut::post_decrementable>);
    static_assert(meta::Decrementable<ut::decrementable>);
    static_assert(!meta::Decrementable<ut::nothing>);
    SUCCEED();
}
