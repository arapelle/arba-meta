#pragma once

#include <arba/cppx/policy/thread_policy.hpp>

#include <mutex>

inline namespace arba
{
namespace meta
{

class dummy_mutex
{
public:
    constexpr dummy_mutex() noexcept = default;
    dummy_mutex(const dummy_mutex&) = delete;

    inline void lock() {}
    [[nodiscard]] inline bool try_lock() { return true; }
    inline void unlock() {}

    inline static dummy_mutex& instance()
    {
        static dummy_mutex mutex_;
        return mutex_;
    }
};

template <cppx::ThreadPolicy, class MutexType = std::mutex>
struct make_mutex_type;

template <class MutexType>
struct make_mutex_type<cppx::thread_safe_t, MutexType>
{
    using type = MutexType;
};

template <class MutexType>
struct make_mutex_type<cppx::thread_unsafe_t, MutexType>
{
    using type = dummy_mutex;
};

template <cppx::ThreadPolicy ThreadPolicyType, class MutexType = std::mutex>
using make_mutex_type_t = typename make_mutex_type<ThreadPolicyType, MutexType>::type;

} // namespace meta
} // namespace arba
