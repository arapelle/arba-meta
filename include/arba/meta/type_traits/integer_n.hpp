#pragma once

#include <arba/meta/policy/thread_policy.hpp>

#include <atomic>
#include <cstdint>
#include <memory>
#include <type_traits>
#include <vector>

inline namespace arba
{
namespace meta
{

// integer_n

template <typename SignType>
concept Signedness = std::is_same_v<SignType, signed> || std::is_same_v<SignType, unsigned>;

template <unsigned BitSize, Signedness = signed, ThreadPolicy = thread_unsafe_t>
    requires((BitSize % 8) == 0 && BitSize > 0 && BitSize <= (sizeof(std::uintmax_t) * 8))
struct integer_n;

template <unsigned BitSize, Signedness SignType = signed, ThreadPolicy ThreadPolicyType = thread_unsafe_t>
using integer_n_t = typename integer_n<BitSize, SignType, ThreadPolicyType>::type;

template <>
struct integer_n<8>
{
    using type = std::int8_t;
};

template <>
struct integer_n<16>
{
    using type = std::int16_t;
};

template <>
struct integer_n<32>
{
    using type = std::int32_t;
};

template <>
struct integer_n<64>
{
    using type = std::int64_t;
};

template <unsigned BitSize>
struct integer_n<BitSize, unsigned>
{
    using type = std::make_unsigned_t<integer_n_t<BitSize>>;
};

template <unsigned BitSize, Signedness SignType>
struct integer_n<BitSize, SignType, thread_safe_t>
{
    using type = std::atomic<integer_n_t<BitSize, SignType>>;
};

// int_n_t

template <unsigned BitSize, ThreadPolicy ThreadPolicyType = thread_unsafe_t>
using int_n_t = typename integer_n<BitSize, signed, ThreadPolicyType>::type;

// uint_n_t

template <unsigned BitSize, ThreadPolicy ThreadPolicyType = thread_unsafe_t>
using uint_n_t = typename integer_n<BitSize, unsigned, ThreadPolicyType>::type;

// atomic_int_n_t

template <unsigned BitSize>
using atomic_int_n_t = typename integer_n<BitSize, signed, thread_safe_t>::type;

// atomic_uint_n_t

template <unsigned BitSize>
using atomic_uint_n_t = typename integer_n<BitSize, unsigned, thread_safe_t>::type;

// integer_least_n

template <unsigned BitSize, Signedness = signed, ThreadPolicy = thread_unsafe_t>
    requires(BitSize > 0 && BitSize <= (sizeof(std::uintmax_t) * 8))
struct integer_least_n;

template <unsigned BitSize, Signedness SignType = signed, ThreadPolicy ThreadPolicyType = thread_unsafe_t>
using integer_least_n_t = typename integer_least_n<BitSize, SignType, ThreadPolicyType>::type;

template <unsigned BitSize>
    requires(BitSize > 0 && BitSize <= 8)
struct integer_least_n<BitSize, signed, thread_unsafe_t> : public integer_n<8, signed, thread_unsafe_t>
{
};

template <unsigned BitSize>
    requires(BitSize > 8 && BitSize <= 16)
struct integer_least_n<BitSize, signed, thread_unsafe_t> : public integer_n<16, signed, thread_unsafe_t>
{
};

template <unsigned BitSize>
    requires(BitSize > 16 && BitSize <= 32)
struct integer_least_n<BitSize, signed, thread_unsafe_t> : public integer_n<32, signed, thread_unsafe_t>
{
};

template <unsigned BitSize>
    requires(BitSize > 32 && BitSize <= 64)
struct integer_least_n<BitSize, signed, thread_unsafe_t> : public integer_n<64, signed, thread_unsafe_t>
{
};

template <unsigned BitSize, Signedness SignType, ThreadPolicy ThreadPolicyType>
    requires(BitSize > 0 && BitSize <= (sizeof(std::uintmax_t) * 8))
struct integer_least_n
{
    using type = typename integer_n<sizeof(integer_least_n_t<BitSize>) * 8, SignType, ThreadPolicyType>::type;
};

// int_least_n_t

template <unsigned BitSize, ThreadPolicy ThreadPolicyType = thread_unsafe_t>
using int_least_n_t = typename integer_least_n<BitSize, signed, ThreadPolicyType>::type;

// uint_least_n_t

template <unsigned BitSize, ThreadPolicy ThreadPolicyType = thread_unsafe_t>
using uint_least_n_t = typename integer_least_n<BitSize, unsigned, ThreadPolicyType>::type;

//// atomic_int_least_n_t

template <unsigned BitSize>
using atomic_int_least_n_t = typename integer_least_n<BitSize, signed, thread_safe_t>::type;

//// atomic_uint_least_n_t

template <unsigned BitSize>
using atomic_uint_least_n_t = typename integer_least_n<BitSize, unsigned, thread_safe_t>::type;

} // namespace meta
} // namespace arba
