#include <arba/meta/type_traits/crtp.hpp>

#include <gtest/gtest.h>

template <class SelfType>
class calculator : public meta::crtp_base<SelfType>
{
public:
    int compute(int x) const { return this->self().factor_value() * x + this->self().offset_value(); }

    int factor_value() const { return 1; }

    int offset_value() const { return 0; }
};

template <class Base, int Factor>
class factor : public Base
{
public:
    int factor_value() const { return Factor; }
};

template <class Base, int Offset>
class offset : public Base
{
public:
    int offset_value() const { return Offset; }
};

template <class SelfType = meta::default_t>
class decorated_calculator
    : public offset<factor<calculator<meta::type_or_default_t<SelfType, decorated_calculator<>>>, 2>, 7>
{
private:
    using base_ = offset<factor<calculator<meta::type_or_default_t<SelfType, decorated_calculator<>>>, 2>, 7>;

public:
    int offset_value() const { return 100 + this->base_::offset_value(); }
};

TEST(decorated_crtp_base_tests, extendable_decorated_crtp_base__self_is_default__ok)
{
    const decorated_calculator calculator;
    static_assert(meta::CrtpBase<decorated_calculator<>>);
    static_assert(!meta::CrtpDecorator<decorated_calculator<>>);
    static_assert(meta::CrtpType<decorated_calculator<>>);
    ASSERT_EQ(calculator.compute(3), 113);
}

template <class Base>
class plus_k : public Base
{
private:
    using base_ = Base;

public:
    int offset_value() const { return 1000 + this->base_::offset_value(); }
};

class final_decorated_calculator : public plus_k<decorated_calculator<final_decorated_calculator>>
{
};

TEST(decorated_crtp_base_tests, final_decorated_base__decorated__ok)
{
    const final_decorated_calculator calculator;
    static_assert(meta::CrtpBase<final_decorated_calculator>);
    static_assert(!meta::CrtpDecorator<final_decorated_calculator>);
    static_assert(meta::CrtpType<final_decorated_calculator>);
    ASSERT_EQ(calculator.compute(3), 1113);
}
