#include <arba/meta/concept/signedness.hpp>

#include <gtest/gtest.h>

TEST(signedness_tests, test_concept)
{
    static_assert(meta::Signedness<signed>);
    static_assert(meta::Signedness<unsigned>);
    static_assert(!meta::Signedness<float>);
    SUCCEED();
}
