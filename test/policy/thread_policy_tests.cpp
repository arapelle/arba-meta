#include <arba/meta/policy/thread_policy.hpp>

#include <gtest/gtest.h>

int func(meta::ThreadPolicy auto)
{
    return 0;
}

int func(meta::thread_safe_t)
{
    return 642;
}

TEST(thread_policy_tests, test_thread_policy)
{
    ASSERT_EQ(func(meta::thread_safe), 642);
    ASSERT_EQ(func(meta::thread_unsafe), 0);
}
