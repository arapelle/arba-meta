#pragma once

#include "default.hpp"

#include <type_traits>

inline namespace arba
{
namespace meta
{

template <class InputType, class OrType>
struct type_or_default;

template <class InputType, class OrType>
    requires(!std::is_same_v<std::remove_cvref_t<InputType>, default_t>)
struct type_or_default<InputType, OrType>
{
    using type = InputType;
    type_or_default() = delete;
};

template <class InputType, class OrType>
    requires(std::is_same_v<std::remove_cvref_t<InputType>, default_t>)
struct type_or_default<InputType, OrType>
{
    using type = OrType;
    type_or_default() = delete;
};

template <class InputType, class OrType>
using type_or_default_t = typename type_or_default<InputType, OrType>::type;

}
}
