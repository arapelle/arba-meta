#pragma once

#include <type_traits>

inline namespace arba
{
namespace meta
{

struct endianness_neutral_t
{
    explicit endianness_neutral_t() = default;
};
constexpr endianness_neutral_t endianness_neutral;

struct endianness_specific_t
{
    explicit endianness_specific_t() = default;
};
constexpr endianness_specific_t endianness_specific;

template <class PolicyType>
concept EndiannessPolicy =
    std::is_same_v<PolicyType, endianness_neutral_t> || std::is_same_v<PolicyType, endianness_specific_t>;

} // namespace meta
} // namespace arba
