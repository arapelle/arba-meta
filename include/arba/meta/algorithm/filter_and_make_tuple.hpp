#pragma once

#include <tuple>
#include <type_traits>

inline namespace arba
{
namespace meta
{
namespace private_
{
template <class TupleType, class... Args>
auto make_specified_tuple_(Args&&... args)
{
    if constexpr (std::is_same_v<TupleType, std::tuple<>>)
    {
        return std::tuple<>();
    }
    else
    {
        return TupleType(std::forward<Args>(args)...);
    }
}
}

template <template <class> typename Predicate, typename... Args>
constexpr auto filter_and_make_tuple(Args&&... args)
{
    return std::tuple_cat(
        private_::make_specified_tuple_<
            std::conditional_t<
                Predicate<std::remove_cvref_t<Args>>::value,
                std::tuple<std::decay_t<Args>>,
                std::tuple<>
                >
            >(args)...
        );
}

template <template <class> typename Predicate, typename... Args>
constexpr auto filter_and_forward_as_tuple(Args&&... args)
{
    return std::tuple_cat(
        private_::make_specified_tuple_<
            std::conditional_t<
                Predicate<std::remove_cvref_t<Args>>::value,
                std::tuple<Args>,
                std::tuple<>
                >
            >(std::forward<Args>(args))...
        );
}
}
}
