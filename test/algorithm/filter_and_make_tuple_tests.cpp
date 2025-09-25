#include <arba/meta/algorithm/filter_and_make_tuple.hpp>

#include <gtest/gtest.h>

template <class Type>
using is_not_pointer_t = std::negation<std::is_pointer<Type>>;

TEST(filter_and_make_tuple_tests, filter_and_make_tuple__args__ok)
{
    int n = 0;
    const double d = 0.5;
    std::string str("str");
    decltype(auto) res = meta::filter_and_make_tuple<is_not_pointer_t>(n, &n, d, &d);
    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(res)>, int>);
    static_assert(std::is_same_v<std::tuple_element_t<1, decltype(res)>, double>);
    static_assert(std::tuple_size_v<decltype(res)> == 2);
    int& nn = std::get<0>(res);
    nn = 1;
    ASSERT_EQ(n, 0);
    ASSERT_EQ(nn, 1);
    ASSERT_EQ(d, 0.5);
}

TEST(filter_and_make_tuple_tests, filter_and_forward_as_tuple__args__ok)
{
    int n = 0;
    const double d = 0.5;
    std::string str("str");
    decltype(auto) res = meta::filter_and_forward_as_tuple<is_not_pointer_t>(n, &n, d, &d);
    static_assert(std::is_same_v<std::tuple_element_t<0, decltype(res)>, int&>);
    static_assert(std::is_same_v<std::tuple_element_t<1, decltype(res)>, const double&>);
    static_assert(std::tuple_size_v<decltype(res)> == 2);
    int& nn = std::get<0>(res);
    nn = 1;
    ASSERT_EQ(n, 1);
    ASSERT_EQ(nn, 1);
    ASSERT_EQ(d, 0.5);
}
