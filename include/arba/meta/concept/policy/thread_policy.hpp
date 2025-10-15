#pragma once

#include <type_traits>

inline namespace arba
{
namespace meta
{

struct thread_safe_t
{
    explicit thread_safe_t() = default;
};
constexpr thread_safe_t thread_safe;

struct thread_unsafe_t
{
    explicit thread_unsafe_t() = default;
};
constexpr thread_unsafe_t thread_unsafe;

template <class PolicyType>
concept ThreadPolicy = std::is_same_v<PolicyType, thread_safe_t> || std::is_same_v<PolicyType, thread_unsafe_t>;

} // namespace meta
} // namespace arba
