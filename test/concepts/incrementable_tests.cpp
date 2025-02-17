
#include "ut/nothing.hpp"
#include <arba/meta/concept/incrementable.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct pre_incrementable
{
    using self_type = pre_incrementable;
    auto& operator++() { return *this; }
};

struct post_incrementable
{
    using self_type = post_incrementable;
    auto operator++(int) { return *this; }
};

struct incrementable
{
    using self_type = incrementable;
    auto& operator++() { return *this; }
    auto operator++(int) { return *this; }
};
} // namespace ut

TEST(incrementable_tests, test_pre_incrementable)
{
    static_assert(meta::PreIncrementable<bool>);
    static_assert(meta::PreIncrementable<char>);
    static_assert(meta::PreIncrementable<int>);
    static_assert(meta::PreIncrementable<unsigned>);
    static_assert(meta::PreIncrementable<int8_t>);
    static_assert(meta::PreIncrementable<int16_t>);
    static_assert(meta::PreIncrementable<int32_t>);
    static_assert(meta::PreIncrementable<int64_t>);
    static_assert(meta::PreIncrementable<intmax_t>);
    static_assert(meta::PreIncrementable<uint8_t>);
    static_assert(meta::PreIncrementable<uint16_t>);
    static_assert(meta::PreIncrementable<uint32_t>);
    static_assert(meta::PreIncrementable<uint64_t>);
    static_assert(meta::PreIncrementable<uintmax_t>);
    static_assert(meta::PreIncrementable<size_t>);
    static_assert(meta::PreIncrementable<float>);
    static_assert(meta::PreIncrementable<double>);
    static_assert(meta::PreIncrementable<ut::pre_incrementable>);
    static_assert(!meta::PreIncrementable<ut::post_incrementable>);
    static_assert(meta::PreIncrementable<ut::incrementable>);
    static_assert(!meta::PreIncrementable<ut::nothing>);
    SUCCEED();
}

TEST(incrementable_tests, test_post_incrementable)
{
    static_assert(meta::PostIncrementable<bool>);
    static_assert(meta::PostIncrementable<char>);
    static_assert(meta::PostIncrementable<int>);
    static_assert(meta::PostIncrementable<unsigned>);
    static_assert(meta::PostIncrementable<int8_t>);
    static_assert(meta::PostIncrementable<int16_t>);
    static_assert(meta::PostIncrementable<int32_t>);
    static_assert(meta::PostIncrementable<int64_t>);
    static_assert(meta::PostIncrementable<intmax_t>);
    static_assert(meta::PostIncrementable<uint8_t>);
    static_assert(meta::PostIncrementable<uint16_t>);
    static_assert(meta::PostIncrementable<uint32_t>);
    static_assert(meta::PostIncrementable<uint64_t>);
    static_assert(meta::PostIncrementable<uintmax_t>);
    static_assert(meta::PostIncrementable<size_t>);
    static_assert(meta::PostIncrementable<float>);
    static_assert(meta::PostIncrementable<double>);
    static_assert(!meta::PostIncrementable<ut::pre_incrementable>);
    static_assert(meta::PostIncrementable<ut::post_incrementable>);
    static_assert(meta::PostIncrementable<ut::incrementable>);
    static_assert(!meta::PostIncrementable<ut::nothing>);
    SUCCEED();
}

TEST(incrementable_tests, test_incrementable)
{
    static_assert(meta::Incrementable<bool>);
    static_assert(meta::Incrementable<char>);
    static_assert(meta::Incrementable<int>);
    static_assert(meta::Incrementable<unsigned>);
    static_assert(meta::Incrementable<int8_t>);
    static_assert(meta::Incrementable<int16_t>);
    static_assert(meta::Incrementable<int32_t>);
    static_assert(meta::Incrementable<int64_t>);
    static_assert(meta::Incrementable<intmax_t>);
    static_assert(meta::Incrementable<uint8_t>);
    static_assert(meta::Incrementable<uint16_t>);
    static_assert(meta::Incrementable<uint32_t>);
    static_assert(meta::Incrementable<uint64_t>);
    static_assert(meta::Incrementable<uintmax_t>);
    static_assert(meta::Incrementable<size_t>);
    static_assert(meta::Incrementable<float>);
    static_assert(meta::Incrementable<double>);
    static_assert(!meta::Incrementable<ut::pre_incrementable>);
    static_assert(!meta::Incrementable<ut::post_incrementable>);
    static_assert(meta::Incrementable<ut::incrementable>);
    static_assert(!meta::Incrementable<ut::nothing>);
    SUCCEED();
}
