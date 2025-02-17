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
