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

template <class InputType, class Callable>
remove_right_reference_t<type_or_default_t<InputType, typename std::invoke_result<Callable>::type>>
value_or_generate(InputType&& input_value, Callable&& gen_default)
{
    if constexpr (!std::is_same_v<std::remove_cvref_t<InputType>, default_t>)
    {
        return std::forward<InputType>(input_value);
    }
    else
    {
        return gen_default();
    }
}

} // namespace meta
} // namespace arba
