#include <arba/meta/type_traits/kwargs.hpp>

#include <gtest/gtest.h>

#include <sstream>
#include <format>
#include <cassert>

namespace ut
{
namespace algo_kwargs
{

ARBA_META_KWARG(frame_width, unsigned);
ARBA_META_KWARG(frame_height, unsigned);
ARBA_META_KWARG(title, std::string);

}

template <typename... Args>
void algo_base(std::string& result, unsigned frame_width, unsigned frame_height, std::string_view title, Args&&... args)
{
    std::ostringstream oss;
    if constexpr (sizeof...(args) > 1)
    {
        (void)(oss << ... << std::forward<Args>(args));
    }
    else
    {
        std::string value(std::move(args)...);
        oss << std::move(value);
    }
    result = std::format("[{}][{}][{}][{}]", frame_width, frame_height, title, oss.str());
}

template <typename... Args>
void algo(std::string& result, Args&&... args)
{
    const meta::kwargs_parser<Args...> kwargs_parser(std::forward<Args>(args)...);
    const unsigned frame_width = kwargs_parser.template arg_or_default<algo_kwargs::frame_width>(200);
    const unsigned frame_height = kwargs_parser.template arg_or_default<algo_kwargs::frame_height>(100);
    const std::string title = kwargs_parser.template arg_or_generate<algo_kwargs::title>([]{ return "title"; });
    kwargs_parser.apply_with_unrecognized_args([](auto&&... as){ algo_base(std::forward<decltype(as)>(as)...); },
                                               std::ref(result), frame_width, frame_height, title);
}
}

TEST(kwargs_with_unregognized_args_tests, kwargs_parser__default_values__ok)
{
    std::string res;
    ut::algo(res);
    ASSERT_EQ(res, "[200][100][title][]");
    ut::algo(res, "cou", "cou");
    ASSERT_EQ(res, "[200][100][title][coucou]");
}

TEST(kwargs_with_unregognized_args_tests, kwargs_parser__provided_values__ok)
{
    using namespace ut::algo_kwargs;

    std::string res;
    ut::algo(res, frame_height(800), title("Arba Meta"), frame_width(1000));
    ASSERT_EQ(res, "[1000][800][Arba Meta][]");
    std::string temp = "coucou";
    ut::algo(res, frame_height(800), title("Arba Meta"), frame_width(1000), std::move(temp));
    ASSERT_EQ(res, "[1000][800][Arba Meta][coucou]");
    ASSERT_EQ(temp, "");
}
