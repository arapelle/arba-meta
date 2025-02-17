#pragma once

#include <concepts>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <typename Type>
concept PreIncrementable = std::is_arithmetic_v<Type> || requires(Type& num) {
    { ++num } -> std::same_as<Type&>;
};

template <typename Type>
concept PostIncrementable = std::is_arithmetic_v<Type> || requires(Type& num) {
    { num++ } -> std::same_as<Type>;
};

template <typename Type>
concept Incrementable = PreIncrementable<Type> && PostIncrementable<Type>;

} // namespace meta
} // namespace arba
