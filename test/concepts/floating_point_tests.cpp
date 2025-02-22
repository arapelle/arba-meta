
#include "ut/nothing.hpp"
#include <arba/meta/concept/floating_point.hpp>

#include <gtest/gtest.h>

namespace ut
{
template <class FT>
struct floating_point
{
    using self_type = floating_point;
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
    using other_type = FT;
    auto& operator+=(const other_type&) { return *this; }
    auto& operator-=(const other_type&) { return *this; }
    auto operator+(const other_type&) const { return *this; }
    auto operator-(const other_type&) const { return *this; }
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto operator*(const other_type&) const { return *this; }
    auto operator/(const other_type&) const { return *this; }
    auto operator<=>(const other_type& arg) const { return arg <=> (arg + arg); }
    floating_point() = default;
    floating_point(const self_type&) = default;
    floating_point(self_type&&) = default;
    explicit floating_point(other_type) {}
    operator other_type() const { return other_type(); }
};
} // namespace ut

TEST(floating_point_tests, test_floating_point__float)
{
    static_assert(meta::Float<bool>);
    static_assert(meta::Float<char>);
    static_assert(meta::Float<int>);
    static_assert(meta::Float<unsigned>);
    static_assert(meta::Float<int8_t>);
    static_assert(meta::Float<int16_t>);
    static_assert(meta::Float<int32_t>);
    static_assert(meta::Float<int64_t>);
    static_assert(meta::Float<intmax_t>);
    static_assert(meta::Float<uint8_t>);
    static_assert(meta::Float<uint16_t>);
    static_assert(meta::Float<uint32_t>);
    static_assert(meta::Float<uint64_t>);
    static_assert(meta::Float<uintmax_t>);
    static_assert(meta::Float<size_t>);
    static_assert(meta::Float<float>);
    static_assert(meta::Float<double>);
    static_assert(meta::Float<ut::floating_point<float>>);
    static_assert(!meta::Float<ut::nothing>);
    SUCCEED();
}

TEST(floating_point_tests, test_floating_point__double)
{
    static_assert(meta::Double<bool>);
    static_assert(meta::Double<char>);
    static_assert(meta::Double<int>);
    static_assert(meta::Double<unsigned>);
    static_assert(meta::Double<int8_t>);
    static_assert(meta::Double<int16_t>);
    static_assert(meta::Double<int32_t>);
    static_assert(meta::Double<int64_t>);
    static_assert(meta::Double<intmax_t>);
    static_assert(meta::Double<uint8_t>);
    static_assert(meta::Double<uint16_t>);
    static_assert(meta::Double<uint32_t>);
    static_assert(meta::Double<uint64_t>);
    static_assert(meta::Double<uintmax_t>);
    static_assert(meta::Double<size_t>);
    static_assert(meta::Double<float>);
    static_assert(meta::Double<double>);
    static_assert(meta::Double<ut::floating_point<double>>);
    static_assert(!meta::Double<ut::nothing>);
    SUCCEED();
}
