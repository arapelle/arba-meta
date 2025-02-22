
#include "ut/nothing.hpp"
#include <arba/meta/concept/integral.hpp>

#include <gtest/gtest.h>

namespace ut
{
template <class IT>
struct integral
{
    using self_type = integral;
    auto& operator--() { return *this; }
    auto& operator++() { return *this; }
    auto operator--(int) { return *this; }
    auto operator++(int) { return *this; }
    auto& operator+=(const self_type&) { return *this; }
    auto& operator-=(const self_type&) { return *this; }
    auto operator+(const self_type&) const { return *this; }
    auto operator-(const self_type&) const { return *this; }
    auto operator-() const { return *this; }
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
    auto& operator%=(const self_type&) { return *this; }
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    auto operator%(const self_type&) const { return *this; }
    auto& operator&=(const self_type&) { return *this; }
    auto& operator|=(const self_type&) { return *this; }
    auto& operator^=(const self_type&) { return *this; }
    auto operator&(const self_type&) const { return *this; }
    auto operator|(const self_type&) const { return *this; }
    auto operator^(const self_type&) const { return *this; }
    auto operator~() const { return *this; }
    auto& operator<<=(const self_type&) { return *this; }
    auto& operator>>=(const self_type&) { return *this; }
    auto operator<<(const self_type&) const { return *this; }
    auto operator>>(const self_type&) const { return *this; }
    auto operator<=>(const self_type&) const = default;
    using other_type = IT;
    auto& operator+=(const other_type&) { return *this; }
    auto& operator-=(const other_type&) { return *this; }
    auto operator+(const other_type&) const { return *this; }
    auto operator-(const other_type&) const { return *this; }
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto& operator%=(const other_type&) { return *this; }
    auto operator*(const other_type&) const { return *this; }
    auto operator/(const other_type&) const { return *this; }
    auto operator%(const other_type&) const { return *this; }
    auto& operator&=(const other_type&) { return *this; }
    auto& operator|=(const other_type&) { return *this; }
    auto& operator^=(const other_type&) { return *this; }
    auto operator&(const other_type&) const { return *this; }
    auto operator|(const other_type&) const { return *this; }
    auto operator^(const other_type&) const { return *this; }
    auto& operator<<=(const other_type&) { return *this; }
    auto& operator>>=(const other_type&) { return *this; }
    auto operator<<(const other_type&) const { return *this; }
    auto operator>>(const other_type&) const { return *this; }
    auto operator<=>(const other_type& arg) const { return arg <=> (arg + arg); }
    integral() = default;
    integral(const self_type&) = default;
    integral(self_type&&) = default;
    explicit integral(other_type) {}
    operator other_type() const { return other_type(); }
};
} // namespace ut

TEST(integral_tests, test_integral__int)
{
    static_assert(meta::Int<bool>);
    static_assert(meta::Int<char>);
    static_assert(meta::Int<int>);
    static_assert(meta::Int<unsigned>);
    static_assert(meta::Int<int8_t>);
    static_assert(meta::Int<int16_t>);
    static_assert(meta::Int<int32_t>);
    static_assert(meta::Int<int64_t>);
    static_assert(meta::Int<intmax_t>);
    static_assert(meta::Int<uint8_t>);
    static_assert(meta::Int<uint16_t>);
    static_assert(meta::Int<uint32_t>);
    static_assert(meta::Int<uint64_t>);
    static_assert(meta::Int<uintmax_t>);
    static_assert(meta::Int<size_t>);
    static_assert(!meta::Int<float>);
    static_assert(!meta::Int<double>);
    static_assert(meta::Int<ut::integral<int>>);
    static_assert(!meta::Int<ut::nothing>);
    SUCCEED();
}

TEST(integral_tests, test_integral__unsigned)
{
    static_assert(meta::UInt<bool>);
    static_assert(meta::UInt<char>);
    static_assert(meta::UInt<int>);
    static_assert(meta::UInt<unsigned>);
    static_assert(meta::UInt<int8_t>);
    static_assert(meta::UInt<int16_t>);
    static_assert(meta::UInt<int32_t>);
    static_assert(meta::UInt<int64_t>);
    static_assert(meta::UInt<intmax_t>);
    static_assert(meta::UInt<uint8_t>);
    static_assert(meta::UInt<uint16_t>);
    static_assert(meta::UInt<uint32_t>);
    static_assert(meta::UInt<uint64_t>);
    static_assert(meta::UInt<uintmax_t>);
    static_assert(meta::UInt<size_t>);
    static_assert(!meta::UInt<float>);
    static_assert(!meta::UInt<double>);
    static_assert(meta::UInt<ut::integral<unsigned>>);
    static_assert(!meta::UInt<ut::nothing>);
    SUCCEED();
}
