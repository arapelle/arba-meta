#pragma once

#include <algorithm>
#include <array>

inline namespace arba
{
namespace meta
{

template <class T, class T1, class T2, std::size_t N, std::size_t M>
    requires std::constructible_from<T, T1> && std::constructible_from<T, T2>
constexpr std::array<T, N + M> concat(const std::array<T1, N>& lhs, const std::array<T2, M>& rhs)
{
    std::array<T, N + M> res;
    const auto iter = std::copy(lhs.cbegin(), lhs.cend(), res.begin());
    std::copy(rhs.cbegin(), rhs.cend(), iter);
    return res;
}

template <class T, std::size_t N, std::size_t M>
inline constexpr std::array<T, N + M> concat(const std::array<T, N>& lhs, const std::array<T, M>& rhs)
{
    return concat<T, T, T, N, M>(lhs, rhs);
}

} // namespace meta
} // namespace arba
