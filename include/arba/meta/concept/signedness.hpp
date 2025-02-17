#pragma once

#include <type_traits>

inline namespace arba
{
namespace meta
{

template <typename SignType>
concept Signedness = std::is_same_v<SignType, signed> || std::is_same_v<SignType, unsigned>;

}
} // namespace arba
