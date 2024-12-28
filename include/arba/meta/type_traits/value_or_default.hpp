#pragma once

#include "default.hpp"
#include "remove_right_reference.hpp"
#include "type_or_default.hpp"

#include <type_traits>
#include <utility>

inline namespace arba
{
namespace meta
{

template <class InputType, class OrType>
remove_right_reference_t<type_or_default_t<InputType, OrType>> value_or_default(InputType&& input_value,
                                                                                OrType&& or_value)
{
    if constexpr (!std::is_same_v<std::remove_cvref_t<InputType>, default_t>)
    {
        return std::forward<InputType>(input_value);
    }
    else
    {
        return std::forward<OrType>(or_value);
    }
}

} // namespace meta
} // namespace arba
