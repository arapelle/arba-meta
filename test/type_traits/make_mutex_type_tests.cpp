#include <arba/meta/type_traits/make_mutex_type.hpp>

#include <gtest/gtest.h>

#include <shared_mutex>

TEST(dummy_mutex_tests, dummy_mutex__with_lock_guard__ok)
{
    {
        std::lock_guard lock(meta::dummy_mutex::instance());
    }
    SUCCEED();
}

TEST(make_mutex_type_tests, make_mutex_type__default_mutex_type__ok)
{
    static_assert(std::is_same_v<meta::make_mutex_type_t<cppx::thread_safe_t>, std::mutex>);
    static_assert(std::is_same_v<meta::make_mutex_type_t<cppx::thread_unsafe_t>, meta::dummy_mutex>);
    SUCCEED();
}

TEST(make_mutex_type_tests, make_mutex_type__other_mutex_type__ok)
{
    static_assert(std::is_same_v<meta::make_mutex_type_t<cppx::thread_safe_t, std::shared_mutex>, std::shared_mutex>);
    static_assert(std::is_same_v<meta::make_mutex_type_t<cppx::thread_unsafe_t, std::shared_mutex>, meta::dummy_mutex>);
    SUCCEED();
}
