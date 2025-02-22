#pragma once

#include "totally_arithmetic.hpp"

inline namespace arba
{
namespace meta
{

template <typename Type, typename IT>
concept Integral =
    std::integral<IT> && TotallyOrderedTotallyArithmetic<Type> && TotallyOrderedTotallyArithmeticWith<Type, IT>
    && std::constructible_from<Type, const IT&> && std::is_convertible_v<Type, IT>;

template <typename Type>
concept Int = Integral<Type, int>;

template <typename Type>
concept UInt = Integral<Type, unsigned>;

} // namespace meta
} // namespace arba
