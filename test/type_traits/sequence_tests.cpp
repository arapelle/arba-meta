#include <arba/meta/type_traits/sequence.hpp>

#include <gtest/gtest.h>

TEST(sequence_tests, front__int_seq__ok)
{
    static_assert(meta::front(std::integer_sequence<unsigned, 6, 4, 2>{}) == 6);
    SUCCEED();
}

TEST(sequence_tests, last__int_seq__ok)
{
    static_assert(meta::last(std::integer_sequence<unsigned, 6, 4, 2>{}) == 2);
    SUCCEED();
}

TEST(sequence_tests, type_sequence_tuple__ok)
{
    static_assert(std::is_same_v<meta::type_sequence<int, float>::tuple, std::tuple<int, float>>);
    SUCCEED();
}

TEST(sequence_tests, type_sequence_size__ok)
{
    static_assert(meta::type_sequence<int, float, std::string>::size() == 3);
    SUCCEED();
}

TEST(sequence_tests, front_type__type_sequence__ok)
{
    static_assert(std::is_same_v<meta::front_type_t<meta::type_sequence<int, float, std::string>>, int>);
    SUCCEED();
}

TEST(sequence_tests, queue_type__type_sequence__ok)
{
    static_assert(std::is_same_v<meta::queue_type_t<meta::type_sequence<int, float, std::string>>,
                                 meta::type_sequence<float, std::string>>);
    SUCCEED();
}

TEST(sequence_tests, queue_type__integer_sequence__ok)
{
    static_assert(
        std::is_same_v<meta::queue_type_t<std::integer_sequence<int, 6, 4, 2>>, std::integer_sequence<int, 4, 2>>);
    SUCCEED();
}

template <int... Values>
class my_int_seq
{
};

TEST(sequence_tests, queue_type__my_int_seq__ok)
{
    static_assert(std::is_same_v<meta::queue_type_t<my_int_seq<6, 4, 2>>, my_int_seq<4, 2>>);
    SUCCEED();
}

TEST(sequence_tests, tuple_element_index__type_in_tuple__ok)
{
    using tuple_t = std::tuple<int, float, double>;
    static_assert(meta::tuple_element_index_v<tuple_t, int> == 0);
    static_assert(meta::tuple_element_index_v<tuple_t, float> == 1);
    static_assert(meta::tuple_element_index_v<tuple_t, double> == 2);
    SUCCEED();
}

TEST(sequence_tests, tuple_element_index__type_not_in_tuple__ok)
{
    using tuple_t = std::tuple<int, float, double>;
    static_assert(meta::tuple_element_index_v<tuple_t, int&> == std::tuple_size_v<tuple_t>);
    static_assert(meta::tuple_element_index_v<tuple_t, int&&> == std::tuple_size_v<tuple_t>);
    static_assert(meta::tuple_element_index_v<tuple_t, const int&> == std::tuple_size_v<tuple_t>);
    static_assert(meta::tuple_element_index_v<tuple_t, std::string> == std::tuple_size_v<tuple_t>);
    SUCCEED();
}

TEST(sequence_tests, decayed_tuple_element_index__type_in_tuple__ok)
{
    using tuple_t = std::tuple<int, float, const double>;
    static_assert(meta::decayed_tuple_element_index_v<tuple_t, int> == 0);
    static_assert(meta::decayed_tuple_element_index_v<tuple_t, float> == 1);
    static_assert(meta::decayed_tuple_element_index_v<tuple_t, double> == 2);
    using ref_tuple_t = std::tuple<int&, float&&, const double&>;
    static_assert(meta::decayed_tuple_element_index_v<ref_tuple_t, int> == 0);
    static_assert(meta::decayed_tuple_element_index_v<ref_tuple_t, float> == 1);
    static_assert(meta::decayed_tuple_element_index_v<ref_tuple_t, double> == 2);
    SUCCEED();
}

TEST(sequence_tests, decayed_tuple_element_index__type_not_in_tuple__ok)
{
    using tuple_t = std::tuple<int&, float&&, const double&>;
    static_assert(meta::decayed_tuple_element_index_v<tuple_t, std::string> == std::tuple_size_v<tuple_t>);
    SUCCEED();
}

TEST(sequence_tests, type_sequence_element_index__type_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int, float, double>;
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, int> == 0);
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, float> == 1);
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, double> == 2);
    SUCCEED();
}

TEST(sequence_tests, type_sequence_element_index__type_not_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int, float, double>;
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, int&> == type_sequence_t::size());
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, int&&> == type_sequence_t::size());
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, const int&> == type_sequence_t::size());
    static_assert(meta::type_sequence_element_index_v<type_sequence_t, std::string> == type_sequence_t::size());
    SUCCEED();
}

TEST(sequence_tests, decayed_type_sequence_element_index__type_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int, float, const double>;
    static_assert(meta::decayed_type_sequence_element_index_v<type_sequence_t, int> == 0);
    static_assert(meta::decayed_type_sequence_element_index_v<type_sequence_t, float> == 1);
    static_assert(meta::decayed_type_sequence_element_index_v<type_sequence_t, double> == 2);
    using ref_type_sequence_t = meta::type_sequence<int&, float&&, const double&>;
    static_assert(meta::decayed_type_sequence_element_index_v<ref_type_sequence_t, int> == 0);
    static_assert(meta::decayed_type_sequence_element_index_v<ref_type_sequence_t, float> == 1);
    static_assert(meta::decayed_type_sequence_element_index_v<ref_type_sequence_t, double> == 2);
    SUCCEED();
}

TEST(sequence_tests, decayed_type_sequence_element_index__type_not_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int&, float&&, const double&>;
    static_assert(meta::decayed_type_sequence_element_index_v<type_sequence_t, std::string> == type_sequence_t::size());
    SUCCEED();
}

TEST(sequence_tests, type_sequence_contains__type_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int, float, double>;
    static_assert(meta::type_sequence_contains_v<type_sequence_t, int>);
    static_assert(meta::type_sequence_contains_v<type_sequence_t, float>);
    static_assert(meta::type_sequence_contains_v<type_sequence_t, double>);
    SUCCEED();
}

TEST(sequence_tests, type_sequence_contains__type_not_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int, float, double>;
    static_assert(!meta::type_sequence_contains_v<type_sequence_t, int&>);
    static_assert(!meta::type_sequence_contains_v<type_sequence_t, int&&>);
    static_assert(!meta::type_sequence_contains_v<type_sequence_t, const int&>);
    static_assert(!meta::type_sequence_contains_v<type_sequence_t, std::string>);
    SUCCEED();
}

TEST(sequence_tests, decayed_type_sequence_contains__type_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int, float, const double>;
    static_assert(meta::decayed_type_sequence_contains_v<type_sequence_t, int>);
    static_assert(meta::decayed_type_sequence_contains_v<type_sequence_t, float>);
    static_assert(meta::decayed_type_sequence_contains_v<type_sequence_t, double>);
    using ref_type_sequence_t = meta::type_sequence<int&, float&&, const double&>;
    static_assert(meta::decayed_type_sequence_contains_v<ref_type_sequence_t, int>);
    static_assert(meta::decayed_type_sequence_contains_v<ref_type_sequence_t, float>);
    static_assert(meta::decayed_type_sequence_contains_v<ref_type_sequence_t, double>);
    SUCCEED();
}

TEST(sequence_tests, decayed_type_sequence_contains__type_not_in_type_sequence__ok)
{
    using type_sequence_t = meta::type_sequence<int&, float&&, const double&>;
    static_assert(!meta::decayed_type_sequence_contains_v<type_sequence_t, std::string>);
    SUCCEED();
}
