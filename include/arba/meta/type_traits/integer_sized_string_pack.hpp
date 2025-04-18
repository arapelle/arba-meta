#pragma once

#include <arba/meta/concept/signedness.hpp>
#include "integer_n.hpp"

#include <string_view>
#include <concepts>
#include <algorithm>

inline namespace arba
{
namespace meta
{

template <Signedness SignType, uint8_t IntegerBitSize, uint8_t StringBitSize>
requires (IntegerBitSize % 8 == 0 && IntegerBitSize > 0
         && StringBitSize % 8 == 0 && StringBitSize > 0)
class integer_sized_string_pack;

namespace private_
{
class integer_sized_string_pack_base_
{
    constexpr integer_sized_string_pack_base_() {}

    template <Signedness SignType, uint8_t IntegerBitSize, uint8_t StringBitSize>
    requires (IntegerBitSize % 8 == 0 && IntegerBitSize > 0
             && StringBitSize % 8 == 0 && StringBitSize > 0)
    friend class meta::integer_sized_string_pack;
};
}

template <Signedness SignType, uint8_t IntegerBitSize, uint8_t StringBitSize>
    requires (IntegerBitSize % 8 == 0 && IntegerBitSize > 0
             && StringBitSize % 8 == 0 && StringBitSize > 0)
    class integer_sized_string_pack : public private_::integer_sized_string_pack_base_
{
    using str_buffer_ = std::array<char, StringBitSize / 8>;

public:
    using integer_type = integer_n_t<IntegerBitSize, SignType>;
    static constexpr std::size_t max_string_size = sizeof(str_buffer_);

    constexpr integer_sized_string_pack(integer_type ival = 0, std::string_view str = "")
        : int_(ival), str_len_(std::min<uint8_t>(static_cast<uint8_t>(str.length()), max_string_size))
    {
        std::copy(str.cbegin(), str.cbegin() + str_len_, str_.begin());
        std::fill(str_.begin() + str_len_, str_.end(), '\0');
    }

    template <std::size_t Size>
    constexpr integer_sized_string_pack(integer_type ival, const char (&str)[Size]) requires (Size <= (max_string_size+1))
        : int_(ival), str_len_(Size - 1)
    {
        std::copy(str, str + (Size - 1), str_.begin());
        std::fill(str_.begin() + (Size - 1), str_.end(), '\0');
    }

    template <std::size_t Size>
    constexpr integer_sized_string_pack(integer_type, const char (&)[Size]) requires (Size > (max_string_size+1)) = delete;

    constexpr integer_type integer() const noexcept { return int_; }

    constexpr std::string_view string() const noexcept { return std::string_view(str_.data(), str_len_); }

    inline constexpr bool operator==(const integer_sized_string_pack& arg) const noexcept
    {
        return int_ == arg.int_ && str_len_ == arg.str_len_ && str_ == arg.str_;
    }
    inline constexpr bool operator!=(const integer_sized_string_pack&) const noexcept = default;

private:
    integer_type int_;
    uint8_t str_len_;
    str_buffer_ str_;
};

template <Signedness SignType, uint8_t IntegerBitSize, uint8_t StringBitSize>
requires (IntegerBitSize <= 32 && StringBitSize <= 48 && IntegerBitSize + StringBitSize <= 56)
    class integer_sized_string_pack64 : public integer_sized_string_pack<SignType, IntegerBitSize, StringBitSize>
{
public:
    using integer_sized_string_pack<SignType, IntegerBitSize, StringBitSize>::integer_sized_string_pack;
};

using i8_sstring48_pack = integer_sized_string_pack64<signed, 8, 48>;
using u8_sstring48_pack = integer_sized_string_pack64<unsigned, 8, 48>;
using i16_sstring40_pack = integer_sized_string_pack64<signed, 16, 40>;
using u16_sstring40_pack = integer_sized_string_pack64<unsigned, 16, 40>;
using i32_sstring24_pack = integer_sized_string_pack64<signed, 32, 24>;
using u32_sstring24_pack = integer_sized_string_pack64<unsigned, 32, 24>;

template <Signedness SignType, uint8_t IntegerBitSize, uint8_t StringBitSize>
requires (IntegerBitSize <= 64 && StringBitSize <= 112 && IntegerBitSize + StringBitSize <= 120)
    class integer_sized_string_pack128 : public integer_sized_string_pack<SignType, IntegerBitSize, StringBitSize>
{
public:
    using integer_sized_string_pack<SignType, IntegerBitSize, StringBitSize>::integer_sized_string_pack;
};

using i8_sstring112_pack = integer_sized_string_pack128<signed, 8, 112>;
using u8_sstring112_pack = integer_sized_string_pack128<unsigned, 8, 112>;
using i16_sstring104_pack = integer_sized_string_pack128<signed, 16, 104>;
using u16_sstring104_pack = integer_sized_string_pack128<unsigned, 16, 104>;
using i32_sstring88_pack = integer_sized_string_pack128<signed, 32, 88>;
using u32_sstring88_pack = integer_sized_string_pack128<unsigned, 32, 88>;
using i64_sstring56_pack = integer_sized_string_pack128<signed, 64, 56>;
using u64_sstring56_pack = integer_sized_string_pack128<unsigned, 64, 56>;

template <class Type>
concept IntegerSizedStringPack = std::is_base_of_v<private_::integer_sized_string_pack_base_, Type>
                                 && requires (const Type& arg)
                                 {
    typename Type::integer_type;
    Type::max_string_size;
    { arg.integer() } -> std::same_as<typename Type::integer_type>;
    { arg.string() } -> std::same_as<std::string_view>;
                                 }
                                 && std::constructible_from<Type, typename Type::integer_type, std::string_view>
                                     && std::constructible_from<Type, typename Type::integer_type, const char (&)[Type::max_string_size+1]>
                                     && (!std::constructible_from<Type, typename Type::integer_type, const char (&)[Type::max_string_size+2]>)
                                     && std::is_same_v<decltype(Type::max_string_size), const std::size_t>
                                     && std::equality_comparable<Type>;

template <class Type>
concept IntegerSizedStringPack64 = sizeof(Type) == 8 && IntegerSizedStringPack<Type>;

template <class Type>
concept IntegerSizedStringPack128 = sizeof(Type) == 16 && IntegerSizedStringPack<Type>;

}
}
