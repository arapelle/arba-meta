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
    using tuple = std::tuple<Args...>;

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

template <typename Tuple, typename T>
struct tuple_element_index;

template <typename T>
struct tuple_element_index<std::tuple<>, T>
{
    static constexpr std::size_t value = 0;
};

template <typename T, typename U, typename... Ts>
struct tuple_element_index<std::tuple<U, Ts...>, T>
{
    static constexpr std::size_t value = std::is_same_v<T, U> ? 0 :
                                             (1 + tuple_element_index<std::tuple<Ts...>, T>::value);
};

template <typename Tuple, typename T>
constexpr std::size_t tuple_element_index_v = tuple_element_index<Tuple, T>::value;

template <typename Tuple, typename T>
struct decayed_tuple_element_index;

template <typename T>
struct decayed_tuple_element_index<std::tuple<>, T>
{
    static constexpr std::size_t value = 0;
};

template <typename T, typename U, typename... Ts>
struct decayed_tuple_element_index<std::tuple<U, Ts...>, T>
{
    static constexpr std::size_t value = std::is_same_v<T, std::decay_t<U>> ? 0 :
                                             (1 + decayed_tuple_element_index<std::tuple<Ts...>, T>::value);
};

template <typename Tuple, typename T>
constexpr std::size_t decayed_tuple_element_index_v = decayed_tuple_element_index<Tuple, T>::value;

template <typename TypeSequence, typename T>
struct type_sequence_element_index;

template <typename T>
struct type_sequence_element_index<type_sequence<>, T>
{
    static constexpr std::size_t value = 0;
};

template <typename T, typename U, typename... Ts>
struct type_sequence_element_index<type_sequence<U, Ts...>, T>
{
    static constexpr std::size_t value = std::is_same_v<T, U> ? 0 :
                                             (1 + type_sequence_element_index<type_sequence<Ts...>, T>::value);
};

template <typename TypeSequence, typename T>
constexpr std::size_t type_sequence_element_index_v = type_sequence_element_index<TypeSequence, T>::value;

template <typename TypeSequence, typename T>
struct decayed_type_sequence_element_index;

template <typename T>
struct decayed_type_sequence_element_index<type_sequence<>, T>
{
    static constexpr std::size_t value = 0;
};

template <typename T, typename U, typename... Ts>
struct decayed_type_sequence_element_index<type_sequence<U, Ts...>, T>
{
    static constexpr std::size_t value = std::is_same_v<T, std::decay_t<U>> ? 0 :
                                             (1 + decayed_type_sequence_element_index<type_sequence<Ts...>, T>::value);
};

template <typename TypeSequence, typename T>
constexpr std::size_t decayed_type_sequence_element_index_v = decayed_type_sequence_element_index<TypeSequence, T>::value;

template <typename TypeSequence, typename T>
struct type_sequence_contains
{
    static constexpr bool value = type_sequence_element_index_v<TypeSequence, T> != TypeSequence::size();
};

template <typename TypeSequence, typename T>
constexpr std::size_t type_sequence_contains_v = type_sequence_contains<TypeSequence, T>::value;

template <typename TypeSequence, typename T>
struct decayed_type_sequence_contains
{
    static constexpr bool value = decayed_type_sequence_element_index_v<TypeSequence, T> != TypeSequence::size();
};

template <typename TypeSequence, typename T>
constexpr std::size_t decayed_type_sequence_contains_v = decayed_type_sequence_contains<TypeSequence, T>::value;

} // namespace meta
} // namespace arba
