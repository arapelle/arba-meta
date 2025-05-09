#include <arba/meta/type_traits/enum.hpp>

#include <gtest/gtest.h>

#include <algorithm>
#include <array>

class PrimaryColors;

class PrimaryColor : public meta::enumerator<int, PrimaryColors, meta::enum_conversion::explicit_conversion>
{
private:
    using base_ = meta::enumerator<int, PrimaryColors, meta::enum_conversion::explicit_conversion>;

public:
    constexpr PrimaryColor() {}
    consteval PrimaryColor(const base_& val) : base_(val) {}
};

class PrimaryColors : public meta::enumeration<PrimaryColor, PrimaryColors>
{
public:
    static constexpr PrimaryColor red = make_enumerator(3);
    static constexpr PrimaryColor blue = make_enumerator(5);
    static constexpr PrimaryColor yellow = make_enumerator(7);

    static constexpr std::array enumerator_names = { "red", "blue", "yellow" };
    static constexpr std::array enumerators{ red, blue, yellow };
};

// ------

class Colors;

class Color : public meta::enumerator<PrimaryColor, Colors>
{
private:
    using base_ = meta::enumerator<PrimaryColor, Colors>;

public:
    constexpr Color() {}
    constexpr Color(const PrimaryColor& val) : base_(val) {}
    consteval Color(const base_& val) : base_(val) {}
};

class Colors : public meta::enumeration<Color, Colors>
{
public:
    static constexpr Color purple = make_enumerator(9);
    static constexpr Color green = make_enumerator(11);
    static constexpr Color orange = make_enumerator(13);

    static constexpr std::array enumerator_names{ "purple", "green", "orange" };
    static constexpr std::array enumerators{ purple, green, orange };
};

// ------

class Shapes;

class Shape : public meta::enumerator<uint8_t, Shapes>
{
private:
    using base_ = meta::enumerator<uint8_t, Shapes>;

public:
    constexpr Shape() {}
    consteval Shape(const base_& val) : base_(val) {}
};

class Shapes : public meta::enumeration<Shape, Shapes>
{
public:
    static constexpr Shape circle = make_enumerator(0);
    static constexpr Shape square = make_enumerator(1);
    static constexpr Shape triangle = make_enumerator(3);
    static constexpr std::array enumerator_names = { "circle", "square", "triangle" };
    static constexpr std::array enumerators{ circle, square, triangle };
};

// ------

TEST(integer_enum_tests, primary_colors__static_assertions__valid)
{
    static_assert(std::is_same_v<PrimaryColor::value_type, int>);
    static_assert(!std::constructible_from<PrimaryColor, PrimaryColor::value_type>);
    static_assert(std::constructible_from<PrimaryColor, PrimaryColor>);
    static_assert(std::is_same_v<PrimaryColor::enumeration, PrimaryColors>);
    static_assert(std::is_same_v<PrimaryColors::enumerator, PrimaryColor>);
    static_assert(!PrimaryColor::implicit);
    static_assert(std::is_same_v<PrimaryColor::base_type, PrimaryColor::value_type>);
    static_assert(std::is_same_v<PrimaryColor::base_type, PrimaryColor::embedded_type>);
    static_assert(std::totally_ordered<PrimaryColor>);
    static_assert(!std::totally_ordered_with<PrimaryColor, PrimaryColor::value_type>);
    static_assert(!std::totally_ordered_with<PrimaryColor, Shape>);
    static_assert(PrimaryColors::enumerator_index_offset() == 3);
    static_assert(PrimaryColors::enumerator_index_factor() == 2);
}

TEST(integer_enum_tests, primary_colors__construction__ok)
{
    PrimaryColor color;
    color = PrimaryColors::blue;
    ASSERT_EQ(color, PrimaryColors::blue);
    ASSERT_EQ(color.value(), 5);
    ASSERT_EQ(color.name(), "blue");
}

TEST(integer_enum_tests, constexpr_primary_colors__construction__ok)
{
    constexpr PrimaryColor color = PrimaryColors::blue;
    ASSERT_EQ(color, PrimaryColors::blue);
    ASSERT_EQ(color.value(), 5);
    ASSERT_EQ(color.name(), "blue");
    static_assert(color == PrimaryColors::blue);
    static_assert(color.value() == 5);
#if __cpp_constexpr >= 202211L
    static_assert(color.name() == "blue");
#endif
}

TEST(integer_enum_tests, primary_colors__value__ok)
{
    ASSERT_EQ(PrimaryColors::red.value(), 3);
    ASSERT_EQ(PrimaryColors::blue.value(), 5);
    ASSERT_EQ(PrimaryColors::yellow.value(), 7);
}

TEST(integer_enum_tests, constexpr_primary_colors__value__ok)
{
    static_assert(PrimaryColors::red.value() == 3);
    static_assert(PrimaryColors::blue.value() == 5);
    static_assert(PrimaryColors::yellow.value() == 7);
}

TEST(integer_enum_tests, primary_colors__index__ok)
{
    ASSERT_EQ(PrimaryColors::red.index(), 0);
    ASSERT_EQ(PrimaryColors::blue.index(), 1);
    ASSERT_EQ(PrimaryColors::yellow.index(), 2);
}

TEST(integer_enum_tests, constexpr_primary_colors__index__ok)
{
    static_assert(PrimaryColors::red.index() == 0);
    static_assert(PrimaryColors::blue.index() == 1);
    static_assert(PrimaryColors::yellow.index() == 2);
}

TEST(integer_enum_tests, primary_colors__name__ok)
{
    ASSERT_EQ(PrimaryColors::red.name(), "red");
    ASSERT_EQ(PrimaryColors::blue.name(), "blue");
    ASSERT_EQ(PrimaryColors::yellow.name(), "yellow");
}

#if __cpp_constexpr >= 202211L
TEST(integer_enum_tests, constexpr_primary_colors__name__ok)
{
    static_assert(PrimaryColors::red.name() == "red");
    static_assert(PrimaryColors::blue.name() == "blue");
    static_assert(PrimaryColors::yellow.name() == "yellow");
}
#endif

TEST(integer_enum_tests, primary_colors__enumeration_size__ok)
{
    ASSERT_EQ(PrimaryColors::size(), 3);
    static_assert(PrimaryColors::size() == 3);
}

TEST(integer_enum_tests, primary_colors__all__ok)
{
    ASSERT_EQ(PrimaryColors::all(), PrimaryColors::enumerators);
    static_assert(PrimaryColors::all() == PrimaryColors::enumerators);
}

TEST(integer_enum_tests, primary_colors__explicit_conversion__ok)
{
    static_assert(!std::convertible_to<PrimaryColor, PrimaryColor::value_type>);
    const PrimaryColor::value_type yellow_value = static_cast<PrimaryColor::value_type>(PrimaryColors::yellow);
    ASSERT_EQ(yellow_value, 7);
}

TEST(integer_enum_tests, primary_colors__hash__ok)
{
    std::hash<PrimaryColor> enumerator_hasher;
    std::hash<PrimaryColor::value_type> value_hasher;
    ASSERT_EQ(enumerator_hasher(PrimaryColors::red), value_hasher(PrimaryColors::red.value()));
}

TEST(integer_enum_tests, primary_colors__format__ok)
{
    ASSERT_EQ(std::format("{}", PrimaryColors::red), "red");
    ASSERT_EQ(std::format("{:v}", PrimaryColors::blue), "5");
    ASSERT_EQ(std::format("{:f}", PrimaryColors::yellow), "(yellow=7)");
}

// ------

TEST(integer_enum_tests, colors_enum__static_assertions__valid)
{
    static_assert(std::is_same_v<Color::value_type, int>);
    static_assert(!std::constructible_from<Color, Color::value_type>);
    static_assert(std::constructible_from<Color, Color>);
    static_assert(std::constructible_from<Color, PrimaryColor>);
    static_assert(!std::constructible_from<Color, Shape>);
    static_assert(std::is_same_v<Color::enumeration, Colors>);
    static_assert(std::is_same_v<Colors::enumerator, Color>);
    static_assert(!Color::implicit);
    static_assert(std::is_same_v<Color::base_type, PrimaryColor>);
    static_assert(std::totally_ordered<Color>);
    static_assert(std::totally_ordered_with<Color, PrimaryColor>);
    static_assert(!std::totally_ordered_with<PrimaryColor, Color::value_type>);
    static_assert(!std::totally_ordered_with<Color, Shape>);
    static_assert(Colors::enumerator_index_offset() == 3);
    static_assert(Colors::enumerator_index_factor() == 2);
}

TEST(integer_enum_tests, colors__construction__ok)
{
    Color color;
    color = Colors::orange;
    ASSERT_EQ(color, Colors::orange);
    ASSERT_EQ(color.value(), 13);
    ASSERT_EQ(color.name(), "orange");
    color = Colors::red;
    ASSERT_EQ(color, Colors::red);
    ASSERT_EQ(color, PrimaryColors::red);
    ASSERT_EQ(color.value(), 3);
    ASSERT_EQ(color.name(), "red");
}

TEST(integer_enum_tests, constexpr_colors__construction__ok)
{
    constexpr Color color = Colors::orange;
    ASSERT_EQ(color, Colors::orange);
    ASSERT_EQ(color.value(), 13);
    ASSERT_EQ(color.name(), "orange");
    static_assert(color == Colors::orange);
    static_assert(color.value() == 13);
#if __cpp_constexpr >= 202211L
    static_assert(color.name() == "orange");
#endif
}

TEST(integer_enum_tests, colors__value__ok)
{
    ASSERT_EQ(Colors::purple.value(), 9);
    ASSERT_EQ(Colors::green.value(), 11);
    ASSERT_EQ(Colors::orange.value(), 13);
}

TEST(integer_enum_tests, constexpr_colors__value__ok)
{
    static_assert(Colors::purple.value() == 9);
    static_assert(Colors::green.value() == 11);
    static_assert(Colors::orange.value() == 13);
}

TEST(integer_enum_tests, colors__name__ok)
{
    ASSERT_EQ(Colors::purple.name(), "purple");
    ASSERT_EQ(Colors::green.name(), "green");
    ASSERT_EQ(Colors::orange.name(), "orange");
}

#if __cpp_constexpr >= 202211L
TEST(integer_enum_tests, constexpr_colors__name__ok)
{
    static_assert(Colors::purple.name() == "purple");
    static_assert(Colors::green.name() == "green");
    static_assert(Colors::orange.name() == "orange");
}
#endif

TEST(integer_enum_tests, colors__enumeration_size__ok)
{
    ASSERT_EQ(Colors::size(), 6);
    static_assert(Colors::size() == 6);
}

TEST(integer_enum_tests, colors__all__ok)
{
    constexpr std::array<Color, 6> expected{ Colors::red,    Colors::blue,  Colors::yellow,
                                             Colors::purple, Colors::green, Colors::orange };
    ASSERT_EQ(Colors::all(), expected);
    static_assert(Colors::all() == expected);
}

TEST(integer_enum_tests, colors__explicit_conversion__ok)
{
    static_assert(!std::convertible_to<Color, Color::value_type>);
    const Color::value_type purple_value = static_cast<Color::value_type>(Colors::purple);
    ASSERT_EQ(purple_value, 9);
}

TEST(integer_enum_tests, colors__hash__ok)
{
    std::hash<Color> enumerator_hasher;
    std::hash<Color::value_type> value_hasher;
    ASSERT_EQ(enumerator_hasher(Colors::green), value_hasher(Colors::green.value()));
}

TEST(integer_enum_tests, colors__format__ok)
{
    ASSERT_EQ(std::format("{}", Colors::orange), "orange");
    ASSERT_EQ(std::format("{:n}", Colors::orange), "orange");
    ASSERT_EQ(std::format("{:v}", Colors::orange), std::format("{}", Colors::orange.value()));
    ASSERT_EQ(std::format("{:f}", Colors::orange), std::format("({}={})", "orange", Colors::orange.value()));
}

// ------

TEST(integer_enum_tests, shapes__index__ok)
{
    ASSERT_EQ(Shapes::circle.index(), 0);
    ASSERT_EQ(Shapes::square.index(), 1);
    ASSERT_EQ(Shapes::triangle.index(), 2);
}

TEST(integer_enum_tests, constexpr_shapes__index__ok)
{
    static_assert(Shapes::circle.index() == 0);
    static_assert(Shapes::square.index() == 1);
    static_assert(Shapes::triangle.index() == 2);
}
