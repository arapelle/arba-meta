#pragma once

#include <atomic>
#include <memory>
#include <type_traits>

inline namespace arba
{
namespace meta
{

template <class Type>
inline constexpr bool is_move_assignable_to_itself_v = std::is_trivially_copyable_v<Type>;

template <class Type>
inline constexpr bool is_move_assignable_to_itself_v<std::unique_ptr<Type>> = true;

template <class Type>
inline constexpr bool is_move_assignable_to_itself_v<std::shared_ptr<Type>> = true;

template <class Type>
    requires std::is_scalar_v<Type>
inline constexpr bool is_move_assignable_to_itself_v<std::atomic<Type>> = true;

template <class Type>
inline constexpr bool is_move_assignable_to_itself_v<std::atomic<std::shared_ptr<Type>>> = true;

} // namespace meta
} // namespace arba
