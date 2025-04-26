#include <arba/meta/type_traits/crtp.hpp>

#include <gtest/gtest.h>

template <class SelfType>
class calculator_base : public meta::crtp_base<SelfType>
{
public:
    int compute(int x) const { return this->self().factor_value() * x + this->self().offset_value(); }

    int factor_value() const { return 2; }

    int offset_value() const { return 7; }
};

class final_calculator : public calculator_base<final_calculator>
{
};

TEST(simple_base_tests, crtp_base__no_decorator__ok)
{
    const final_calculator calculator;
    static_assert(meta::CrtpBase<final_calculator>);
    static_assert(!meta::CrtpDecorator<final_calculator>);
    static_assert(meta::CrtpType<final_calculator>);
    ASSERT_EQ(calculator.compute(1), 9);
    ASSERT_EQ(calculator.compute(3), 13);
}
