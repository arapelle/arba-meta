#pragma once

#include <new> // nothrow
#include <type_traits>

inline namespace arba
{
namespace meta
{

struct maythrow_t
{
    explicit maythrow_t() = default;
};
constexpr maythrow_t maythrow;

#ifdef NDEBUG
using smartthrow_t = std::nothrow_t;
#else
using smartthrow_t = maythrow_t;
#endif
constexpr smartthrow_t smartthrow;

template <class PolicyType>
concept ExceptionPolicy = std::is_same_v<PolicyType, std::nothrow_t> || std::is_same_v<PolicyType, maythrow_t>;

} // namespace meta
} // namespace arba
