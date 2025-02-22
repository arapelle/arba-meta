#pragma once

#include <concepts>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <typename Type>
concept MultiplicativeAssignable = std::is_arithmetic_v<Type> || requires(Type num, const Type& cnum) {
    { num *= cnum } -> std::same_as<Type&>;
    { num /= cnum } -> std::same_as<Type&>;
};

template <typename Type>
concept Multipliable = std::is_arithmetic_v<Type> || (MultiplicativeAssignable<Type> && requires(const Type& cnum) {
                           { cnum* cnum } -> std::convertible_to<Type>;
                           { cnum / cnum } -> std::convertible_to<Type>;
                       });

template <typename Type>
concept ModuloableAssignable = MultiplicativeAssignable<Type> && requires(Type num, const Type& cnum) {
    { num %= cnum } -> std::same_as<Type&>;
};

template <typename Type>
concept Moduloable = ModuloableAssignable<Type> && Multipliable<Type> && requires(const Type& cnum) {
    { cnum % cnum } -> std::convertible_to<Type>;
};

template <typename LeftType, typename RightType>
concept MultiplicativeAssignableWith = requires(LeftType lhs, const RightType& crhs) {
    { lhs *= crhs } -> std::same_as<LeftType&>;
    { lhs /= crhs } -> std::same_as<LeftType&>;
};

template <typename LeftType, typename RightType>
concept MultipliableWith =
    MultiplicativeAssignableWith<LeftType, RightType> && requires(const LeftType& clhs, const RightType& crhs) {
        { clhs* crhs } -> Multipliable;
        { clhs / crhs } -> Multipliable;
    };

template <typename LeftType, typename RightType>
concept ModuloableAssignableWith =
    MultiplicativeAssignableWith<LeftType, RightType> && requires(LeftType lhs, const RightType& crhs) {
        { lhs %= crhs } -> std::same_as<LeftType&>;
    };

template <typename LeftType, typename RightType>
concept ModuloableWith = ModuloableAssignableWith<LeftType, RightType> && MultipliableWith<LeftType, RightType>
                         && requires(const LeftType& clhs, const RightType& crhs) {
                                { clhs % crhs } -> Moduloable;
                            };

} // namespace meta
} // namespace arba
