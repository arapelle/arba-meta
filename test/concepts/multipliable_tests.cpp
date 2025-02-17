
#include "ut/nothing.hpp"
#include <arba/meta/concept/multipliable.hpp>

#include <gtest/gtest.h>

namespace ut
{
struct multiplicative_assignable
{
    using self_type = multiplicative_assignable;
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
};

struct multipliable
{
    using self_type = multipliable;
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
};

struct moduloable_assignable
{
    using self_type = moduloable_assignable;
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
    auto& operator%=(const self_type&) { return *this; }
};

struct moduloable
{
    using self_type = moduloable;
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
    auto& operator%=(const self_type&) { return *this; }
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    auto operator%(const self_type&) const { return *this; }
};
} // namespace ut

TEST(multipliable_tests, test_multiplicative_assignable)
{
    static_assert(meta::MultiplicativeAssignable<bool>);
    static_assert(meta::MultiplicativeAssignable<char>);
    static_assert(meta::MultiplicativeAssignable<int>);
    static_assert(meta::MultiplicativeAssignable<unsigned>);
    static_assert(meta::MultiplicativeAssignable<int8_t>);
    static_assert(meta::MultiplicativeAssignable<int16_t>);
    static_assert(meta::MultiplicativeAssignable<int32_t>);
    static_assert(meta::MultiplicativeAssignable<int64_t>);
    static_assert(meta::MultiplicativeAssignable<intmax_t>);
    static_assert(meta::MultiplicativeAssignable<uint8_t>);
    static_assert(meta::MultiplicativeAssignable<uint16_t>);
    static_assert(meta::MultiplicativeAssignable<uint32_t>);
    static_assert(meta::MultiplicativeAssignable<uint64_t>);
    static_assert(meta::MultiplicativeAssignable<uintmax_t>);
    static_assert(meta::MultiplicativeAssignable<size_t>);
    static_assert(meta::MultiplicativeAssignable<float>);
    static_assert(meta::MultiplicativeAssignable<double>);
    static_assert(meta::MultiplicativeAssignable<ut::multiplicative_assignable>);
    static_assert(meta::MultiplicativeAssignable<ut::multipliable>);
    static_assert(meta::MultiplicativeAssignable<ut::moduloable_assignable>);
    static_assert(meta::MultiplicativeAssignable<ut::moduloable>);
    static_assert(!meta::MultiplicativeAssignable<ut::nothing>);
    SUCCEED();
}

TEST(multipliable_tests, test_multipliable)
{
    static_assert(meta::Multipliable<bool>);
    static_assert(meta::Multipliable<char>);
    static_assert(meta::Multipliable<int>);
    static_assert(meta::Multipliable<unsigned>);
    static_assert(meta::Multipliable<int8_t>);
    static_assert(meta::Multipliable<int16_t>);
    static_assert(meta::Multipliable<int32_t>);
    static_assert(meta::Multipliable<int64_t>);
    static_assert(meta::Multipliable<intmax_t>);
    static_assert(meta::Multipliable<uint8_t>);
    static_assert(meta::Multipliable<uint16_t>);
    static_assert(meta::Multipliable<uint32_t>);
    static_assert(meta::Multipliable<uint64_t>);
    static_assert(meta::Multipliable<uintmax_t>);
    static_assert(meta::Multipliable<size_t>);
    static_assert(meta::Multipliable<float>);
    static_assert(meta::Multipliable<double>);
    static_assert(!meta::Multipliable<ut::multiplicative_assignable>);
    static_assert(meta::Multipliable<ut::multipliable>);
    static_assert(!meta::Multipliable<ut::moduloable_assignable>);
    static_assert(meta::Multipliable<ut::moduloable>);
    static_assert(!meta::Multipliable<ut::nothing>);
    SUCCEED();
}

TEST(multipliable_tests, test_moduloable_assignable)
{
    static_assert(meta::ModuloableAssignable<bool>);
    static_assert(meta::ModuloableAssignable<char>);
    static_assert(meta::ModuloableAssignable<int>);
    static_assert(meta::ModuloableAssignable<unsigned>);
    static_assert(meta::ModuloableAssignable<int8_t>);
    static_assert(meta::ModuloableAssignable<int16_t>);
    static_assert(meta::ModuloableAssignable<int32_t>);
    static_assert(meta::ModuloableAssignable<int64_t>);
    static_assert(meta::ModuloableAssignable<intmax_t>);
    static_assert(meta::ModuloableAssignable<uint8_t>);
    static_assert(meta::ModuloableAssignable<uint16_t>);
    static_assert(meta::ModuloableAssignable<uint32_t>);
    static_assert(meta::ModuloableAssignable<uint64_t>);
    static_assert(meta::ModuloableAssignable<uintmax_t>);
    static_assert(meta::ModuloableAssignable<size_t>);
    static_assert(!meta::ModuloableAssignable<float>);
    static_assert(!meta::ModuloableAssignable<double>);
    static_assert(!meta::ModuloableAssignable<ut::multiplicative_assignable>);
    static_assert(!meta::ModuloableAssignable<ut::multipliable>);
    static_assert(meta::ModuloableAssignable<ut::moduloable_assignable>);
    static_assert(meta::ModuloableAssignable<ut::moduloable>);
    static_assert(!meta::ModuloableAssignable<ut::nothing>);
    SUCCEED();
}

TEST(multipliable_tests, test_moduloable)
{
    static_assert(meta::Moduloable<bool>);
    static_assert(meta::Moduloable<char>);
    static_assert(meta::Moduloable<int>);
    static_assert(meta::Moduloable<unsigned>);
    static_assert(meta::Moduloable<int8_t>);
    static_assert(meta::Moduloable<int16_t>);
    static_assert(meta::Moduloable<int32_t>);
    static_assert(meta::Moduloable<int64_t>);
    static_assert(meta::Moduloable<intmax_t>);
    static_assert(meta::Moduloable<uint8_t>);
    static_assert(meta::Moduloable<uint16_t>);
    static_assert(meta::Moduloable<uint32_t>);
    static_assert(meta::Moduloable<uint64_t>);
    static_assert(meta::Moduloable<uintmax_t>);
    static_assert(meta::Moduloable<size_t>);
    static_assert(!meta::Moduloable<float>);
    static_assert(!meta::Moduloable<double>);
    static_assert(!meta::Moduloable<ut::multiplicative_assignable>);
    static_assert(!meta::Moduloable<ut::multipliable>);
    static_assert(!meta::Moduloable<ut::moduloable_assignable>);
    static_assert(meta::Moduloable<ut::moduloable>);
    static_assert(!meta::Moduloable<ut::nothing>);
    SUCCEED();
}

namespace ut
{
struct multiplicative_assignable_with
{
    using self_type = multiplicative_assignable_with;
    using other_type = unsigned;
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
};

struct multipliable_with
{
    using self_type = multipliable_with;
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    using other_type = unsigned;
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto operator*(const other_type&) const { return *this; }
    auto operator/(const other_type&) const { return *this; }
};
} // namespace ut

TEST(multipliable_tests, test_multiplicative_assignable_with)
{
    using other_type = unsigned;
    static_assert(meta::MultiplicativeAssignableWith<bool, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<char, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<int, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<unsigned, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<int8_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<int16_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<int32_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<int64_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<intmax_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<uint8_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<uint16_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<uint32_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<uint64_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<uintmax_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<size_t, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<float, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<double, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<ut::multiplicative_assignable_with, other_type>);
    static_assert(meta::MultiplicativeAssignableWith<ut::multipliable_with, other_type>);
    static_assert(!meta::MultiplicativeAssignableWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(multipliable_tests, test_multipliable_with)
{
    using other_type = unsigned;
    static_assert(meta::MultipliableWith<bool, other_type>);
    static_assert(meta::MultipliableWith<char, other_type>);
    static_assert(meta::MultipliableWith<int, other_type>);
    static_assert(meta::MultipliableWith<unsigned, other_type>);
    static_assert(meta::MultipliableWith<int8_t, other_type>);
    static_assert(meta::MultipliableWith<int16_t, other_type>);
    static_assert(meta::MultipliableWith<int32_t, other_type>);
    static_assert(meta::MultipliableWith<int64_t, other_type>);
    static_assert(meta::MultipliableWith<intmax_t, other_type>);
    static_assert(meta::MultipliableWith<uint8_t, other_type>);
    static_assert(meta::MultipliableWith<uint16_t, other_type>);
    static_assert(meta::MultipliableWith<uint32_t, other_type>);
    static_assert(meta::MultipliableWith<uint64_t, other_type>);
    static_assert(meta::MultipliableWith<uintmax_t, other_type>);
    static_assert(meta::MultipliableWith<size_t, other_type>);
    static_assert(meta::MultipliableWith<float, other_type>);
    static_assert(meta::MultipliableWith<double, other_type>);
    static_assert(!meta::MultipliableWith<ut::multiplicative_assignable_with, other_type>);
    static_assert(meta::MultipliableWith<ut::multipliable_with, other_type>);
    static_assert(!meta::MultipliableWith<ut::nothing, other_type>);
    SUCCEED();
}

namespace ut
{
struct moduloable_assignable_with
{
    using self_type = moduloable_assignable_with;
    using other_type = unsigned;
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto& operator%=(const other_type&) { return *this; }
};

struct moduloable_with
{
    using self_type = moduloable_with;
    auto& operator*=(const self_type&) { return *this; }
    auto& operator/=(const self_type&) { return *this; }
    auto& operator%=(const self_type&) { return *this; }
    auto operator*(const self_type&) const { return *this; }
    auto operator/(const self_type&) const { return *this; }
    auto operator%(const self_type&) const { return *this; }
    using other_type = unsigned;
    auto& operator*=(const other_type&) { return *this; }
    auto& operator/=(const other_type&) { return *this; }
    auto& operator%=(const other_type&) { return *this; }
    auto operator*(const other_type&) const { return *this; }
    auto operator/(const other_type&) const { return *this; }
    auto operator%(const other_type&) const { return *this; }
};
} // namespace ut

TEST(multipliable_tests, test_moduloable_assignable_with)
{
    using other_type = unsigned;
    static_assert(meta::ModuloableAssignableWith<bool, other_type>);
    static_assert(meta::ModuloableAssignableWith<char, other_type>);
    static_assert(meta::ModuloableAssignableWith<int, other_type>);
    static_assert(meta::ModuloableAssignableWith<unsigned, other_type>);
    static_assert(meta::ModuloableAssignableWith<int8_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<int16_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<int32_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<int64_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<intmax_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<uint8_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<uint16_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<uint32_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<uint64_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<uintmax_t, other_type>);
    static_assert(meta::ModuloableAssignableWith<size_t, other_type>);
    static_assert(!meta::ModuloableAssignableWith<float, other_type>);
    static_assert(!meta::ModuloableAssignableWith<double, other_type>);
    static_assert(!meta::ModuloableAssignableWith<ut::multiplicative_assignable_with, other_type>);
    static_assert(!meta::ModuloableAssignableWith<ut::multipliable_with, other_type>);
    static_assert(meta::ModuloableAssignableWith<ut::moduloable_assignable_with, other_type>);
    static_assert(meta::ModuloableAssignableWith<ut::moduloable_with, other_type>);
    static_assert(!meta::ModuloableAssignableWith<ut::nothing, other_type>);
    SUCCEED();
}

TEST(multipliable_tests, test_moduloable_with)
{
    using other_type = unsigned;
    static_assert(meta::ModuloableWith<bool, other_type>);
    static_assert(meta::ModuloableWith<char, other_type>);
    static_assert(meta::ModuloableWith<int, other_type>);
    static_assert(meta::ModuloableWith<unsigned, other_type>);
    static_assert(meta::ModuloableWith<int8_t, other_type>);
    static_assert(meta::ModuloableWith<int16_t, other_type>);
    static_assert(meta::ModuloableWith<int32_t, other_type>);
    static_assert(meta::ModuloableWith<int64_t, other_type>);
    static_assert(meta::ModuloableWith<intmax_t, other_type>);
    static_assert(meta::ModuloableWith<uint8_t, other_type>);
    static_assert(meta::ModuloableWith<uint16_t, other_type>);
    static_assert(meta::ModuloableWith<uint32_t, other_type>);
    static_assert(meta::ModuloableWith<uint64_t, other_type>);
    static_assert(meta::ModuloableWith<uintmax_t, other_type>);
    static_assert(meta::ModuloableWith<size_t, other_type>);
    static_assert(!meta::ModuloableWith<float, other_type>);
    static_assert(!meta::ModuloableWith<double, other_type>);
    static_assert(!meta::ModuloableWith<ut::multiplicative_assignable_with, other_type>);
    static_assert(!meta::ModuloableWith<ut::multipliable_with, other_type>);
    static_assert(!meta::ModuloableWith<ut::moduloable_assignable_with, other_type>);
    static_assert(meta::ModuloableWith<ut::moduloable_with, other_type>);
    static_assert(!meta::ModuloableWith<ut::nothing, other_type>);
    SUCCEED();
}
