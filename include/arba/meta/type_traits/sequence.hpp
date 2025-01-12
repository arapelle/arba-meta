#pragma once

#include <cstddef>
#include <utility>

inline namespace arba
{
namespace meta
{

template <class T, T FirstInt, T... Ints>
consteval T front(std::integer_sequence<T, FirstInt, Ints...>)
{
    return FirstInt;
}

template <class T, T LastInt>
consteval T last(std::integer_sequence<T, LastInt>)
{
    return LastInt;
}

template <class T, T FirstInt, T SecondInt, T... Ints>
consteval T last(std::integer_sequence<T, FirstInt, SecondInt, Ints...>)
{
    return last(std::integer_sequence<T, SecondInt, Ints...>{});
}

template <typename... Args>
struct type_sequence
{
    static constexpr size_t size() noexcept { return sizeof...(Args); }
};

template <class T>
struct front_type;

template <typename Arg, typename... Args>
struct front_type<type_sequence<Arg, Args...>>
{
    using type = Arg;
};

template <class T>
using front_type_t = typename front_type<T>::type;

template <class T>
struct queue_type;

template <class T, T FirstInt, T... Ints>
struct queue_type<std::integer_sequence<T, FirstInt, Ints...>>
{
    using type = std::integer_sequence<T, Ints...>;
};

template <class T, template <T...> class ValueSequence, T FirstValue, T... Values>
struct queue_type<ValueSequence<FirstValue, Values...>>
{
    using type = ValueSequence<Values...>;
};

template <template <class... U> class TypeSequence, typename Arg, typename... Args>
struct queue_type<TypeSequence<Arg, Args...>>
{
    using type = TypeSequence<Args...>;
};

template <class T>
using queue_type_t = typename queue_type<T>::type;

} // namespace meta
} // namespace arba
