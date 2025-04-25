#include <arba/meta/policy/endianness_policy.hpp>

#include <gtest/gtest.h>

uint16_t func(uint16_t n, meta::EndiannessPolicy auto)
{
    return n;
}

uint16_t func(uint16_t n, meta::endianness_neutral_t)
{
    return (n << 8) | (n >> 8);
}

TEST(endianness_policy_tests, test_endianness_policy)
{
    ASSERT_EQ(func(64, meta::endianness_specific), 64);
    ASSERT_EQ(func(0x0064, meta::endianness_neutral), 0x6400);
}
