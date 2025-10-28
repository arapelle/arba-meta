#pragma once

#include <source_location>
#include <type_traits>
#include <utility>

inline namespace arba
{
namespace meta
{

template <class Type>
struct paired_with_source_location : public std::pair<Type, std::source_location>
{
    paired_with_source_location(const Type& arg, const std::source_location loc = std::source_location::current())
        : std::pair<Type, std::source_location>(arg, loc)
    {
    }

    paired_with_source_location(Type&& arg, const std::source_location loc = std::source_location::current())
        : std::pair<Type, std::source_location>(std::forward<Type>(arg), loc)
    {
    }

    template <class Tp>
        requires(std::convertible_to<Tp, Type>)
    paired_with_source_location(const Tp& arg, const std::source_location loc = std::source_location::current())
        : std::pair<Type, std::source_location>(Type(arg), loc)
    {
    }

    template <class Tp>
        requires(std::convertible_to<Tp, Type>)
    paired_with_source_location(Tp&& arg, const std::source_location loc = std::source_location::current())
        : std::pair<Type, std::source_location>(Type(std::forward<Tp>(arg)), loc)
    {
    }
};

} // namespace meta
} // namespace arba
