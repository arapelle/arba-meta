#pragma once

#include "arithmetic.hpp"

inline namespace arba
{
namespace meta
{

template <typename Type, typename FP>
concept FloatingPoint =
    std::floating_point<FP> && TotallyOrderedArithmetic<Type> && TotallyOrderedArithmeticWith<Type, FP>
    && std::constructible_from<Type, const FP&> && std::is_convertible_v<Type, FP>;

template <typename Type>
concept Float = FloatingPoint<Type, float>;

template <typename Type>
concept Double = FloatingPoint<Type, double>;

} // namespace meta
} // namespace arba
