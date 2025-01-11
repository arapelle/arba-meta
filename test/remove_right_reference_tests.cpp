#include <arba/meta/type_traits/remove_right_reference.hpp>

#include <gtest/gtest.h>

#include <format>
#include <string>

TEST(remove_right_reference_tests, remove_right_reference_t__ok)
{
    ASSERT_TRUE((std::is_same_v<meta::remove_right_reference_t<int>, int>));
    ASSERT_TRUE((std::is_same_v<meta::remove_right_reference_t<int&>, int&>));
    ASSERT_TRUE((std::is_same_v<meta::remove_right_reference_t<int&&>, int>));
}
