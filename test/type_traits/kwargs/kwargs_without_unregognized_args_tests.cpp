#include <arba/meta/type_traits/kwargs.hpp>

#include <gtest/gtest.h>

#include <format>

namespace ut
{
namespace algo_kwargs
{

ARBA_META_KWARG(frame_width, unsigned);
ARBA_META_KWARG(frame_height, unsigned);
ARBA_META_KWARG(title, std::string);

} // namespace algo_kwargs

template <typename... Kwargs>
    requires(meta::Kwarg<Kwargs, algo_kwargs::frame_width, algo_kwargs::frame_height, algo_kwargs::title> && ...)
void algo(std::string& result, Kwargs&&... kwargs)
{
    const meta::kwargs_parser<Kwargs...> kwargs_parser(std::forward<Kwargs>(kwargs)...);
    const unsigned frame_width = kwargs_parser.template arg_or_default<algo_kwargs::frame_width>(200);
    const unsigned frame_height = kwargs_parser.template arg_or_default<algo_kwargs::frame_height>(100);
    const std::string title = kwargs_parser.template arg_or_generate<algo_kwargs::title>([] { return "title"; });
    result = std::format("[{}][{}][{}]", frame_width, frame_height, title);
}

namespace algo_ref_kwargs
{
ARBA_META_KWARG(frame_width, unsigned&);
ARBA_META_KWARG(frame_height, const unsigned&);
} // namespace algo_ref_kwargs

template <typename... Kwargs>
    requires(meta::Kwarg<Kwargs, algo_ref_kwargs::frame_width, algo_ref_kwargs::frame_height> && ...)
void algo_ref(std::string& result, Kwargs&&... kwargs)
{
    const meta::kwargs_parser<Kwargs...> kwargs_parser(std::forward<Kwargs>(kwargs)...);
    unsigned default_frame_width = 234, default_frame_height = 678;
    unsigned& frame_width =
        kwargs_parser.template arg_or_default<algo_ref_kwargs::frame_width>(std::ref(default_frame_width));
    frame_width += 1000;
    const unsigned& frame_height =
        kwargs_parser.template arg_or_default<algo_ref_kwargs::frame_height>(std::cref(default_frame_height));
    result = std::format("[{}][{}]", frame_width, frame_height);
}
} // namespace ut

TEST(kwargs_without_unregognized_args_tests, kwargs_parser__default_values__ok)
{
    std::string res;
    ut::algo(res);
    ASSERT_EQ(res, "[200][100][title]");
}

TEST(kwargs_without_unregognized_args_tests, kwargs_parser__provided_values__ok)
{
    using namespace ut::algo_kwargs;

    std::string res;
    ut::algo(res, frame_height(800), title("Arba Meta"), frame_width(1000));
    ASSERT_EQ(res, "[1000][800][Arba Meta]");
}

TEST(kwargs_without_unregognized_args_tests, kwargs_parser__default_values_ref__ok)
{
    using namespace ut::algo_ref_kwargs;

    std::string res;
    unsigned f_width = 0;
    unsigned f_height = 0;
    ut::algo_ref(res);
    ASSERT_EQ(res, "[1234][678]");
    ASSERT_EQ(f_width, 0);
    ASSERT_EQ(f_height, 0);
}

TEST(kwargs_without_unregognized_args_tests, kwargs_parser__provided_values_ref__ok)
{
    using namespace ut::algo_ref_kwargs;

    std::string res;
    unsigned f_width = 111;
    unsigned f_height = 222;
    ut::algo_ref(res, frame_width(std::ref(f_width)), frame_height(std::cref(f_height)));
    ASSERT_EQ(res, "[1111][222]");
    ASSERT_EQ(f_width, 1111);
    ASSERT_EQ(f_height, 222);
}
