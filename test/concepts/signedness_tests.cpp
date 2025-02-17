#include <arba/meta/concepts/signedness.hpp>

#include <gtest/gtest.h>

template <meta::Signedness Type>
consteval bool is_signedness(Type)
{
    return true;
}

template <typename Type>
consteval bool is_signedness(Type)
{
    return false;
}

TEST(signedness_tests, test_concept)
{
    static_assert(is_signedness(signed{}));
    static_assert(is_signedness(unsigned{}));
    static_assert(!is_signedness(float{}));
    SUCCEED();
}
