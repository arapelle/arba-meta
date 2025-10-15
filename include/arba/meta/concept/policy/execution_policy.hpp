#pragma once

#include <execution>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <class Type>
concept ExecutionPolicy = std::is_execution_policy_v<Type>;

}
}
