#pragma once

#include <concepts>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <typename Type>
concept BitwiseShiftableAssignable = requires(Type num, const Type& cnum) {
    { num <<= cnum } -> std::same_as<Type&>;
    { num >>= cnum } -> std::same_as<Type&>;
};

template <typename Type>
concept BitwiseShiftable = BitwiseShiftableAssignable<Type> && requires(const Type& cnum) {
    { cnum << cnum } -> std::convertible_to<Type>;
    { cnum >> cnum } -> std::convertible_to<Type>;
};

template <typename LeftType, typename RightType>
concept BitwiseShiftableAssignableWith = requires(LeftType lhs, const RightType& crhs) {
    { lhs <<= crhs } -> std::same_as<LeftType&>;
    { lhs >>= crhs } -> std::same_as<LeftType&>;
};

template <typename LeftType, typename RightType>
concept BitwiseShiftableWith =
    BitwiseShiftableAssignableWith<LeftType, RightType> && requires(const LeftType& clhs, const RightType& crhs) {
        { clhs << crhs } -> BitwiseShiftable;
        { clhs >> crhs } -> BitwiseShiftable;
    };

} // namespace meta
} // namespace arba
