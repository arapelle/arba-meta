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

template <class PolicyType>
concept ExceptionPolicy = std::is_same_v<PolicyType, std::nothrow_t> || std::is_same_v<PolicyType, maythrow_t>;

}
}
