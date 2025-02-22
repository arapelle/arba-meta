#pragma once

#include "addable.hpp"
#include "multipliable.hpp"

inline namespace arba
{
namespace meta
{

template <typename Type>
concept Arithmetic = Addable<Type> && Multipliable<Type>;

template <typename Type>
concept TotallyOrderedArithmetic = std::totally_ordered<Type> && Arithmetic<Type>;

template <typename LeftType, typename RightType>
concept ArithmeticWith = AddableWith<LeftType, RightType> && MultipliableWith<LeftType, RightType>;

template <typename LeftType, typename RightType>
concept TotallyOrderedArithmeticWith =
    std::totally_ordered_with<LeftType, RightType> && ArithmeticWith<LeftType, RightType>;

} // namespace meta
} // namespace arba
