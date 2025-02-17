
#include "ut/nothing.hpp"
#include <arba/meta/concept/arithmetic.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct arithmetic
{
    using self_type = arithmetic;
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
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
};

struct totally_ordered_arithmetic
{
    using self_type = totally_ordered_arithmetic;
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
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    auto operator<=>(const self_type&) const = default;
};
} // namespace ut

TEST(arithmetic_tests, test_arithmetic)
{
    static_assert(meta::Arithmetic<bool>);
    static_assert(meta::Arithmetic<char>);
    static_assert(meta::Arithmetic<int>);
    static_assert(meta::Arithmetic<unsigned>);
    static_assert(meta::Arithmetic<int8_t>);
    static_assert(meta::Arithmetic<int16_t>);
    static_assert(meta::Arithmetic<int32_t>);
    static_assert(meta::Arithmetic<int64_t>);
    static_assert(meta::Arithmetic<intmax_t>);
    static_assert(meta::Arithmetic<uint8_t>);
    static_assert(meta::Arithmetic<uint16_t>);
    static_assert(meta::Arithmetic<uint32_t>);
    static_assert(meta::Arithmetic<uint64_t>);
    static_assert(meta::Arithmetic<uintmax_t>);
    static_assert(meta::Arithmetic<size_t>);
    static_assert(meta::Arithmetic<float>);
    static_assert(meta::Arithmetic<double>);
    static_assert(meta::Arithmetic<ut::arithmetic>);
    static_assert(meta::Arithmetic<ut::totally_ordered_arithmetic>);
    static_assert(!meta::Arithmetic<ut::nothing>);
    SUCCEED();
}

TEST(arithmetic_tests, test_totally_oredered_arithmetic)
{
    static_assert(meta::TotallyOrderedArithmetic<bool>);
    static_assert(meta::TotallyOrderedArithmetic<char>);
    static_assert(meta::TotallyOrderedArithmetic<int>);
    static_assert(meta::TotallyOrderedArithmetic<unsigned>);
    static_assert(meta::TotallyOrderedArithmetic<int8_t>);
    static_assert(meta::TotallyOrderedArithmetic<int16_t>);
    static_assert(meta::TotallyOrderedArithmetic<int32_t>);
    static_assert(meta::TotallyOrderedArithmetic<int64_t>);
    static_assert(meta::TotallyOrderedArithmetic<intmax_t>);
    static_assert(meta::TotallyOrderedArithmetic<uint8_t>);
    static_assert(meta::TotallyOrderedArithmetic<uint16_t>);
    static_assert(meta::TotallyOrderedArithmetic<uint32_t>);
    static_assert(meta::TotallyOrderedArithmetic<uint64_t>);
    static_assert(meta::TotallyOrderedArithmetic<uintmax_t>);
    static_assert(meta::TotallyOrderedArithmetic<size_t>);
    static_assert(meta::TotallyOrderedArithmetic<float>);
    static_assert(meta::TotallyOrderedArithmetic<double>);
    static_assert(!meta::TotallyOrderedArithmetic<ut::arithmetic>);
    static_assert(meta::TotallyOrderedArithmetic<ut::totally_ordered_arithmetic>);
    static_assert(!meta::TotallyOrderedArithmetic<ut::nothing>);
    SUCCEED();
}

namespace ut
{
struct arithmetic_with
{
    using self_type = arithmetic_with;
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
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    using other_type = unsigned;
    auto& operator+=(const other_type&) { return *this; }
    auto& operator-=(const other_type&) { return *this; }
    auto operator+(const other_type&) const { return *this; }
    auto operator-(const other_type&) const { return *this; }
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto operator*(const other_type&) const { return *this; }
    auto operator/(const other_type&) const { return *this; }
};

struct totally_ordered_arithmetic_with
{
    using self_type = totally_ordered_arithmetic_with;
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
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    auto operator<=>(const self_type&) const = default;
    using other_type = unsigned;
    auto& operator+=(const other_type&) { return *this; }
    auto& operator-=(const other_type&) { return *this; }
    auto operator+(const other_type&) const { return *this; }
    auto operator-(const other_type&) const { return *this; }
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto operator*(const other_type&) const { return *this; }
    auto operator/(const other_type&) const { return *this; }
    auto operator<=>(const other_type& arg) const { return arg <=> (arg + arg); }
    totally_ordered_arithmetic_with() = default;
    totally_ordered_arithmetic_with(const self_type&) = default;
    totally_ordered_arithmetic_with(self_type&&) = default;
    explicit totally_ordered_arithmetic_with(other_type) {}
    operator other_type() const { return other_type(); }
};
} // namespace ut

TEST(arithmetic_tests, test_arithmetic_with)
{
    using other_type = unsigned;
    static_assert(meta::ArithmeticWith<bool, other_type>);
    static_assert(meta::ArithmeticWith<char, other_type>);
    static_assert(meta::ArithmeticWith<int, other_type>);
    static_assert(meta::ArithmeticWith<unsigned, other_type>);
    static_assert(meta::ArithmeticWith<int8_t, other_type>);
    static_assert(meta::ArithmeticWith<int16_t, other_type>);
    static_assert(meta::ArithmeticWith<int32_t, other_type>);
    static_assert(meta::ArithmeticWith<int64_t, other_type>);
    static_assert(meta::ArithmeticWith<intmax_t, other_type>);
    static_assert(meta::ArithmeticWith<uint8_t, other_type>);
    static_assert(meta::ArithmeticWith<uint16_t, other_type>);
    static_assert(meta::ArithmeticWith<uint32_t, other_type>);
    static_assert(meta::ArithmeticWith<uint64_t, other_type>);
    static_assert(meta::ArithmeticWith<uintmax_t, other_type>);
    static_assert(meta::ArithmeticWith<size_t, other_type>);
    static_assert(meta::ArithmeticWith<float, other_type>);
    static_assert(meta::ArithmeticWith<double, other_type>);
    static_assert(meta::ArithmeticWith<ut::arithmetic_with, other_type>);
    static_assert(meta::ArithmeticWith<ut::totally_ordered_arithmetic_with, other_type>);
    static_assert(!meta::ArithmeticWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(arithmetic_tests, test_totally_ordered_arithmetic_with)
{
    using other_type = unsigned;
    static_assert(meta::TotallyOrderedArithmeticWith<bool, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<char, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<int, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<unsigned, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<int8_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<int16_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<int32_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<int64_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<intmax_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<uint8_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<uint16_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<uint32_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<uint64_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<uintmax_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<size_t, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<float, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<double, other_type>);
    static_assert(!meta::TotallyOrderedArithmeticWith<ut::arithmetic_with, other_type>);
    static_assert(meta::TotallyOrderedArithmeticWith<ut::totally_ordered_arithmetic_with, other_type>);
    static_assert(!meta::TotallyOrderedArithmeticWith<ut::nothing, other_type>);
    SUCCEED();
}
