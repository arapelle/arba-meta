
#include "ut/nothing.hpp"
#include <arba/meta/concept/totally_arithmetic.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct totally_arithmetic
{
    using self_type = totally_arithmetic;
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
};

struct totally_ordered_totally_arithmetic
{
    using self_type = totally_ordered_totally_arithmetic;
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
};
} // namespace ut

TEST(totally_arithmetic_tests, test_totally_arithmetic)
{
    static_assert(meta::TotallyArithmetic<bool>);
    static_assert(meta::TotallyArithmetic<char>);
    static_assert(meta::TotallyArithmetic<int>);
    static_assert(meta::TotallyArithmetic<unsigned>);
    static_assert(meta::TotallyArithmetic<int8_t>);
    static_assert(meta::TotallyArithmetic<int16_t>);
    static_assert(meta::TotallyArithmetic<int32_t>);
    static_assert(meta::TotallyArithmetic<int64_t>);
    static_assert(meta::TotallyArithmetic<intmax_t>);
    static_assert(meta::TotallyArithmetic<uint8_t>);
    static_assert(meta::TotallyArithmetic<uint16_t>);
    static_assert(meta::TotallyArithmetic<uint32_t>);
    static_assert(meta::TotallyArithmetic<uint64_t>);
    static_assert(meta::TotallyArithmetic<uintmax_t>);
    static_assert(meta::TotallyArithmetic<size_t>);
    static_assert(!meta::TotallyArithmetic<float>);
    static_assert(!meta::TotallyArithmetic<double>);
    static_assert(meta::TotallyArithmetic<ut::totally_arithmetic>);
    static_assert(meta::TotallyArithmetic<ut::totally_ordered_totally_arithmetic>);
    static_assert(!meta::TotallyArithmetic<ut::nothing>);
    SUCCEED();
}

TEST(totally_arithmetic_tests, test_totally_oredered_totally_arithmetic)
{
    static_assert(meta::TotallyOrderedTotallyArithmetic<bool>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<char>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<int>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<unsigned>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<int8_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<int16_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<int32_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<int64_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<intmax_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<uint8_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<uint16_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<uint32_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<uint64_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<uintmax_t>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<size_t>);
    static_assert(!meta::TotallyOrderedTotallyArithmetic<float>);
    static_assert(!meta::TotallyOrderedTotallyArithmetic<double>);
    static_assert(!meta::TotallyOrderedTotallyArithmetic<ut::totally_arithmetic>);
    static_assert(meta::TotallyOrderedTotallyArithmetic<ut::totally_ordered_totally_arithmetic>);
    static_assert(!meta::TotallyOrderedTotallyArithmetic<ut::nothing>);
    SUCCEED();
}

namespace ut
{
struct totally_arithmetic_with
{
    using self_type = totally_arithmetic_with;
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
    using other_type = unsigned;
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
};

struct totally_ordered_totally_arithmetic_with
{
    using self_type = totally_ordered_totally_arithmetic_with;
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
    using other_type = unsigned;
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
    totally_ordered_totally_arithmetic_with() = default;
    totally_ordered_totally_arithmetic_with(const self_type&) = default;
    totally_ordered_totally_arithmetic_with(self_type&&) = default;
    explicit totally_ordered_totally_arithmetic_with(other_type) {}
    operator other_type() const { return other_type(); }
};
} // namespace ut

TEST(arithmetic_tests, test_totally_arithmetic_with)
{
    using other_type = unsigned;
    static_assert(meta::TotallyArithmeticWith<bool, other_type>);
    static_assert(meta::TotallyArithmeticWith<char, other_type>);
    static_assert(meta::TotallyArithmeticWith<int, other_type>);
    static_assert(meta::TotallyArithmeticWith<unsigned, other_type>);
    static_assert(meta::TotallyArithmeticWith<int8_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<int16_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<int32_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<int64_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<intmax_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<uint8_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<uint16_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<uint32_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<uint64_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<uintmax_t, other_type>);
    static_assert(meta::TotallyArithmeticWith<size_t, other_type>);
    static_assert(!meta::TotallyArithmeticWith<float, other_type>);
    static_assert(!meta::TotallyArithmeticWith<double, other_type>);
    static_assert(meta::TotallyArithmeticWith<ut::totally_arithmetic_with, other_type>);
    static_assert(meta::TotallyArithmeticWith<ut::totally_ordered_totally_arithmetic_with, other_type>);
    static_assert(!meta::TotallyArithmeticWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(arithmetic_tests, test_totally_ordered_totally_arithmetic_with)
{
    using other_type = unsigned;
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<bool, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<char, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<int, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<unsigned, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<int8_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<int16_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<int32_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<int64_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<intmax_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<uint8_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<uint16_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<uint32_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<uint64_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<uintmax_t, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<size_t, other_type>);
    static_assert(!meta::TotallyOrderedTotallyArithmeticWith<float, other_type>);
    static_assert(!meta::TotallyOrderedTotallyArithmeticWith<double, other_type>);
    static_assert(!meta::TotallyOrderedTotallyArithmeticWith<ut::totally_arithmetic_with, other_type>);
    static_assert(meta::TotallyOrderedTotallyArithmeticWith<ut::totally_ordered_totally_arithmetic_with, other_type>);
    static_assert(!meta::TotallyOrderedTotallyArithmeticWith<ut::nothing, other_type>);
    SUCCEED();
}
