#pragma once

inline namespace arba
{
namespace meta
{

template <typename Type>
struct remove_right_reference
{
    using type = Type;
};

template <typename Type>
struct remove_right_reference<Type&>
{
    using type = Type&;
};

template <typename Type>
struct remove_right_reference<Type&&>
{
    using type = Type;
};

template <typename Type>
using remove_right_reference_t = typename remove_right_reference<Type>::type;

} // namespace meta
} // namespace arba
