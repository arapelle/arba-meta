#pragma once

#include "addable.hpp"
#include "bitwise_logical.hpp"
#include "bitwise_shiftable.hpp"
#include "multipliable.hpp"

inline namespace arba
{
namespace meta
{

template <typename Type>
concept TotallyArithmetic = Addable<Type> && Moduloable<Type> && BitwiseLogical<Type> && BitwiseShiftable<Type>;

template <typename Type>
concept TotallyOrderedTotallyArithmetic = std::totally_ordered<Type> && TotallyArithmetic<Type>;

template <typename LeftType, typename RightType>
concept TotallyArithmeticWith = AddableWith<LeftType, RightType> && ModuloableWith<LeftType, RightType>
                                && BitwiseLogicalWith<LeftType, RightType> && BitwiseShiftableWith<LeftType, RightType>;

template <typename LeftType, typename RightType>
concept TotallyOrderedTotallyArithmeticWith =
    std::totally_ordered_with<LeftType, RightType> && TotallyArithmeticWith<LeftType, RightType>;

} // namespace meta
} // namespace arba
