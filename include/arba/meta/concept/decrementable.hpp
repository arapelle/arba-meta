#pragma once

#include <concepts>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <typename Type>
concept PreDecrementable = std::is_arithmetic_v<Type> || requires(Type& num) {
    { --num } -> std::same_as<Type&>;
};

template <typename Type>
concept PostDecrementable = std::is_arithmetic_v<Type> || requires(Type& num) {
    { num-- } -> std::same_as<Type>;
};

template <typename Type>
concept Decrementable = PreDecrementable<Type> && PostDecrementable<Type>;

} // namespace meta
} // namespace arba
