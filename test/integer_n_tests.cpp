#include <arba/meta/type_traits/integer_n.hpp>
#include <format>
#include <gtest/gtest.h>
#include <string>

TEST(integer_n_tests, integer_n__ok)
{
    static_assert(std::is_same_v<meta::int_n_t<8>, int8_t>);
    static_assert(std::is_same_v<meta::int_n_t<16>, int16_t>);
    static_assert(std::is_same_v<meta::int_n_t<32>, int32_t>);
    static_assert(std::is_same_v<meta::int_n_t<64>, int64_t>);
    static_assert(std::is_same_v<meta::int_n_t<sizeof(intmax_t) * 8>, intmax_t>);

    static_assert(std::is_same_v<meta::uint_n_t<8>, uint8_t>);
    static_assert(std::is_same_v<meta::uint_n_t<16>, uint16_t>);
    static_assert(std::is_same_v<meta::uint_n_t<32>, uint32_t>);
    static_assert(std::is_same_v<meta::uint_n_t<64>, uint64_t>);
    static_assert(std::is_same_v<meta::uint_n_t<sizeof(uintmax_t) * 8>, uintmax_t>);

    static_assert(std::is_same_v<meta::int_n_t<8, meta::thread_safe_t>, std::atomic_int8_t>);
    static_assert(std::is_same_v<meta::int_n_t<16, meta::thread_safe_t>, std::atomic_int16_t>);
    static_assert(std::is_same_v<meta::int_n_t<32, meta::thread_safe_t>, std::atomic_int32_t>);
    static_assert(std::is_same_v<meta::int_n_t<64, meta::thread_safe_t>, std::atomic_int64_t>);
    static_assert(std::is_same_v<meta::int_n_t<sizeof(intmax_t) * 8, meta::thread_safe_t>, std::atomic_intmax_t>);

    static_assert(std::is_same_v<meta::uint_n_t<8, meta::thread_safe_t>, std::atomic_uint8_t>);
    static_assert(std::is_same_v<meta::uint_n_t<16, meta::thread_safe_t>, std::atomic_uint16_t>);
    static_assert(std::is_same_v<meta::uint_n_t<32, meta::thread_safe_t>, std::atomic_uint32_t>);
    static_assert(std::is_same_v<meta::uint_n_t<64, meta::thread_safe_t>, std::atomic_uint64_t>);
    static_assert(std::is_same_v<meta::uint_n_t<sizeof(uintmax_t) * 8, meta::thread_safe_t>, std::atomic_uintmax_t>);

    SUCCEED();
}

TEST(integer_n_tests, atomic_integer_n__ok)
{
    static_assert(std::is_same_v<meta::atomic_int_n_t<8>, std::atomic_int8_t>);
    static_assert(std::is_same_v<meta::atomic_int_n_t<16>, std::atomic_int16_t>);
    static_assert(std::is_same_v<meta::atomic_int_n_t<32>, std::atomic_int32_t>);
    static_assert(std::is_same_v<meta::atomic_int_n_t<64>, std::atomic_int64_t>);

    static_assert(std::is_same_v<meta::atomic_uint_n_t<8>, std::atomic_uint8_t>);
    static_assert(std::is_same_v<meta::atomic_uint_n_t<16>, std::atomic_uint16_t>);
    static_assert(std::is_same_v<meta::atomic_uint_n_t<32>, std::atomic_uint32_t>);
    static_assert(std::is_same_v<meta::atomic_uint_n_t<64>, std::atomic_uint64_t>);

    SUCCEED();
}

template <class ExpectedIntegerType, unsigned Min, unsigned Max, meta::Signedness SignType = signed,
          meta::ThreadPolicy ThreadPolicyType = meta::thread_unsafe_t>
    requires(Min <= Max)
constexpr void check_integer_least_n()
{
    if constexpr (std::is_same_v<SignType, signed>)
    {
        static_assert(std::is_same_v<meta::int_least_n_t<Min, ThreadPolicyType>, ExpectedIntegerType>);
    }
    else
    {
        static_assert(std::is_same_v<meta::uint_least_n_t<Min, ThreadPolicyType>, ExpectedIntegerType>);
    }

    if constexpr (Min < Max)
    {
        check_integer_least_n<ExpectedIntegerType, Min + 1, Max, SignType, ThreadPolicyType>();
    }
}

TEST(integer_n_tests, integer_least_n__ok)
{
    check_integer_least_n<int8_t, 1, 8>();
    check_integer_least_n<int16_t, 9, 16>();
    check_integer_least_n<int32_t, 17, 32>();
    check_integer_least_n<int64_t, 33, 64>();

    check_integer_least_n<uint8_t, 1, 8, unsigned>();
    check_integer_least_n<uint16_t, 9, 16, unsigned>();
    check_integer_least_n<uint32_t, 17, 32, unsigned>();
    check_integer_least_n<uint64_t, 33, 64, unsigned>();

    check_integer_least_n<std::atomic_int8_t, 1, 8, signed, meta::thread_safe_t>();
    check_integer_least_n<std::atomic_int16_t, 9, 16, signed, meta::thread_safe_t>();
    check_integer_least_n<std::atomic_int32_t, 17, 32, signed, meta::thread_safe_t>();
    check_integer_least_n<std::atomic_int64_t, 33, 64, signed, meta::thread_safe_t>();

    check_integer_least_n<std::atomic_uint8_t, 1, 8, unsigned, meta::thread_safe_t>();
    check_integer_least_n<std::atomic_uint16_t, 9, 16, unsigned, meta::thread_safe_t>();
    check_integer_least_n<std::atomic_uint32_t, 17, 32, unsigned, meta::thread_safe_t>();
    check_integer_least_n<std::atomic_uint64_t, 33, 64, unsigned, meta::thread_safe_t>();

    SUCCEED();
}

template <class ExpectedIntegerType, unsigned Min, unsigned Max, meta::Signedness SignType = signed>
    requires(Min <= Max)
constexpr void check_atomic_integer_least_n()
{
    if constexpr (std::is_same_v<SignType, signed>)
    {
        static_assert(std::is_same_v<meta::atomic_int_least_n_t<Min>, ExpectedIntegerType>);
    }
    else
    {
        static_assert(std::is_same_v<meta::atomic_uint_least_n_t<Min>, ExpectedIntegerType>);
    }

    if constexpr (Min < Max)
    {
        check_atomic_integer_least_n<ExpectedIntegerType, Min + 1, Max, SignType>();
    }
}

TEST(integer_n_tests, atomic_integer_least_n__ok)
{
    check_atomic_integer_least_n<std::atomic_int8_t, 1, 8, signed>();
    check_atomic_integer_least_n<std::atomic_int16_t, 9, 16, signed>();
    check_atomic_integer_least_n<std::atomic_int32_t, 17, 32, signed>();
    check_atomic_integer_least_n<std::atomic_int64_t, 33, 64, signed>();

    check_atomic_integer_least_n<std::atomic_uint8_t, 1, 8, unsigned>();
    check_atomic_integer_least_n<std::atomic_uint16_t, 9, 16, unsigned>();
    check_atomic_integer_least_n<std::atomic_uint32_t, 17, 32, unsigned>();
    check_atomic_integer_least_n<std::atomic_uint64_t, 33, 64, unsigned>();

    SUCCEED();
}
