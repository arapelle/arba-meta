#pragma once

#include <concepts>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <typename Type>
concept BitwiseLogicalAssignable = requires(Type num, const Type& cnum) {
    { num &= cnum } -> std::same_as<Type&>;
    { num |= cnum } -> std::same_as<Type&>;
    { num ^= cnum } -> std::same_as<Type&>;
};

template <typename Type>
concept BitwiseLogical = BitwiseLogicalAssignable<Type> && requires(const Type& cnum) {
    { cnum& cnum } -> std::convertible_to<Type>;
    { cnum | cnum } -> std::convertible_to<Type>;
    { cnum ^ cnum } -> std::convertible_to<Type>;
} && (std::integral<Type> || requires(const Type& cnum) {
                             { ~cnum } -> std::same_as<Type>;
                         });

template <typename LeftType, typename RightType>
concept BitwiseLogicalAssignableWith = requires(LeftType lhs, const RightType& crhs) {
    { lhs &= crhs } -> std::same_as<LeftType&>;
    { lhs |= crhs } -> std::same_as<LeftType&>;
    { lhs ^= crhs } -> std::same_as<LeftType&>;
};

template <typename LeftType, typename RightType>
concept BitwiseLogicalWith =
    BitwiseLogicalAssignableWith<LeftType, RightType> && requires(const LeftType& clhs, const RightType& crhs) {
        { clhs& crhs } -> BitwiseLogical;
        { clhs | crhs } -> BitwiseLogical;
        { clhs ^ crhs } -> BitwiseLogical;
    } && (std::integral<LeftType> || requires(const LeftType& cnum) {
        { ~cnum } -> std::same_as<LeftType>;
    });

} // namespace meta
} // namespace arba
