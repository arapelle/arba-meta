#include <arba/meta/type_traits/enum.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <array>

// ------

class Fruits;

class Fruit : public meta::enumerator<std::string_view, Fruits>
{
private:
    using base_ = meta::enumerator<std::string_view, Fruits>;

public:
    constexpr Fruit() {}
    consteval Fruit(const base_& val) : base_(val) {}
};

class Fruits : public meta::enumeration<Fruit, Fruits>
{
public:
    static constexpr Fruit banana = make_enumerator("banana");
    static constexpr Fruit ananas = make_enumerator("ananas");

    static constexpr std::array enumerators{ banana, ananas };
};

TEST(string_enum_tests, string_enum__static_assertions__valid)
{
    static_assert(std::is_same_v<Fruit::value_type, std::string_view>);
    static_assert(!std::constructible_from<Fruit, std::string_view>);
    static_assert(std::constructible_from<Fruit, Fruit>);
    static_assert(std::is_same_v<Fruit::enumeration, Fruits>);
    static_assert(std::is_same_v<Fruits::enumerator, Fruit>);
    static_assert(Fruit::implicit);
    static_assert(std::is_same_v<Fruit::base_type, Fruit::value_type>);
    static_assert(std::totally_ordered<Fruit>);
}

TEST(string_enum_tests, string_enum__construction__ok)
{
    Fruit fruit;
    fruit = Fruits::banana;
    ASSERT_EQ(fruit, Fruits::banana);
    ASSERT_EQ(fruit.value(), "banana");
    ASSERT_EQ(fruit.name(), "banana");
}

TEST(string_enum_tests, constexpr_string_enum__construction__ok)
{
    constexpr Fruit fruit = Fruits::banana;
    ASSERT_EQ(fruit, Fruits::banana);
    ASSERT_EQ(fruit.value(), "banana");
    ASSERT_EQ(fruit.name(), "banana");
    static_assert(fruit == Fruits::banana);
    static_assert(fruit.value() == "banana");
#if __cpp_constexpr >= 202211L
    static_assert(fruit.name() == "banana");
#endif
}

TEST(string_enum_tests, constexpr_string_enum__constexpr_enumerator_use__ok)
{
    ASSERT_EQ(Fruits::banana.value(), "banana");
    ASSERT_EQ(Fruits::banana.name(), "banana");
    static_assert(Fruits::banana.value() == "banana");
#if __cpp_constexpr >= 202211L
    static_assert(Fruits::banana.name() == "banana");
#endif
}

TEST(string_enum_tests, string_enum__enumeration_size__ok)
{
    ASSERT_EQ(Fruits::size(), 2);
    static_assert(Fruits::size() == 2);
}

TEST(string_enum_tests, string_enum__all__ok)
{
    ASSERT_EQ(Fruits::all(), Fruits::enumerators);
    static_assert(Fruits::all() == Fruits::enumerators);
}

TEST(string_enum_tests, string_enum__implicit_conversion__ok)
{
    static_assert(std::convertible_to<Fruit, std::string_view>);
    const std::string_view banana_strv = Fruits::banana;
    ASSERT_EQ(banana_strv, "banana");
}

TEST(string_enum_tests, string_enum__hash__ok)
{
    std::hash<Fruit> fruit_hasher;
    std::hash<std::string_view> sv_hasher;
    ASSERT_EQ(fruit_hasher(Fruits::banana), sv_hasher(Fruits::banana.value()));
}

TEST(string_enum_tests, string_enum__format__ok)
{
    ASSERT_EQ(std::format("{}", Fruits::ananas), "ananas");
    ASSERT_EQ(std::format("{:v}", Fruits::ananas), "ananas");
    ASSERT_EQ(std::format("{:f}", Fruits::ananas), "(ananas=ananas)");
}
