#include <arba/meta/version.hpp>

#include <gtest/gtest.h>

TEST(project_version_tests, test_version_core)
{
    constexpr unsigned major = 0;
    constexpr unsigned minor = 2;
    constexpr unsigned patch = 0;
    static_assert(arba::meta::version.core() == arba::vrsn::numver(major, minor, patch));
}
