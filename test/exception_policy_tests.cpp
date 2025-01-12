#include <arba/meta/policy/exception_policy.hpp>

#include <gtest/gtest.h>

int func(meta::ExceptionPolicy auto)
{
    return 0;
}

int func(meta::maythrow_t)
{
    return 642;
}

TEST(exception_policy_tests, test_exception_policy)
{
    ASSERT_EQ(func(meta::maythrow), 642);
    ASSERT_EQ(func(std::nothrow), 0);
#ifdef NDEBUG
    ASSERT_EQ(func(meta::smartthrow), 0);
#else
    ASSERT_EQ(func(meta::smartthrow), 642);
#endif
}
