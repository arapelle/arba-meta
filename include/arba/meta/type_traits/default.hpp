#pragma once

inline namespace arba
{
namespace meta
{

struct default_t
{
    explicit default_t() = default;
};
constexpr default_t default_v;

}
}
