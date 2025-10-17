#include <arba/meta/concept/policy/execution_policy.hpp>

#include <gtest/gtest.h>

int func(meta::ExecutionPolicy auto)
{
    return 0;
}

int func(std::execution::parallel_policy)
{
    return 642;
}

TEST(execution_policy_tests, test_execution_policy)
{
    ASSERT_EQ(func(std::execution::par), 642);
    ASSERT_EQ(func(std::execution::seq), 0);
    ASSERT_EQ(func(std::execution::unseq), 0);
    ASSERT_EQ(func(std::execution::par_unseq), 0);
}
