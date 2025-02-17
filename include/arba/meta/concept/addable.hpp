#pragma once

#include "decrementable.hpp"
#include "incrementable.hpp"

inline namespace arba
{
namespace meta
{

template <typename Type>
concept AdditiveAssignable = std::is_arithmetic_v<Type> || requires(Type num, const Type& cnum) {
    { num += cnum } -> std::same_as<Type&>;
    { num -= cnum } -> std::same_as<Type&>;
};

template <typename Type>
concept Addable =
    std::is_arithmetic_v<Type>
    || (AdditiveAssignable<Type> && Incrementable<Type> && Decrementable<Type> && requires(const Type& cnum) {
           { cnum + cnum } -> std::convertible_to<Type>;
           { cnum - cnum } -> std::convertible_to<Type>;
           { -cnum } -> std::same_as<Type>;
       });

template <typename LeftType, typename RightType>
concept AdditiveAssignableWith = requires(LeftType lhs, const RightType& crhs) {
    { lhs += crhs } -> std::same_as<LeftType&>;
    { lhs -= crhs } -> std::same_as<LeftType&>;
};

template <typename LeftType, typename RightType>
concept AddableWith =
    AdditiveAssignableWith<LeftType, RightType> && requires(const LeftType& clhs, const RightType& crhs) {
        { clhs + crhs } -> Addable;
        { clhs - crhs } -> Addable;
    };

} // namespace meta
} // namespace arba
