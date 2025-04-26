#include <arba/meta/type_traits/crtp.hpp>

#include <gtest/gtest.h>

template <class SelfType>
class calculator_base : public meta::crtp_base<SelfType>
{
public:
    template <class OtherSelf>
    using rebind_t = calculator_base<OtherSelf>;

public:
    int compute(int x) const { return this->self().factor_value() * x + this->self().offset_value(); }

    int factor_value() const { return 1; }

    int offset_value() const { return 0; }
};

template <class Base, int Factor>
class factor : public Base
{
public:
    template <class OtherSelf>
    using rebind_t = factor<meta::rebind_t<Base, OtherSelf>, Factor>;

    template <meta::CrtpBase OtherBase>
    using rebase_t =
        meta::conditional_rebase_t<Base, factor<OtherBase, Factor>, factor<meta::rebase_t<Base, OtherBase>, Factor>>;

    int factor_value() const { return Factor; }
};

template <class Base, int Offset>
class offset : public Base
{
public:
    template <class OtherSelf>
    using rebind_t = offset<meta::rebind_t<Base, OtherSelf>, Offset>;

    template <meta::CrtpBase OtherBase>
    using rebase_t =
        meta::conditional_rebase_t<Base, offset<OtherBase, Offset>, offset<meta::rebase_t<Base, OtherBase>, Offset>>;

    int offset_value() const { return Offset; }
};

using offset_factor_decorator = offset<factor<meta::crtp_decorator, 2>, 7>;

template <class SelfType = meta::default_t>
class decorated_calculator
    : public meta::decorate_t<calculator_base<meta::type_or_default_t<SelfType, decorated_calculator<>>>,
                              offset_factor_decorator>
{
private:
    using base_ = meta::decorate_t<calculator_base<meta::type_or_default_t<SelfType, decorated_calculator<>>>,
                                   offset_factor_decorator>;

public:
    template <class OtherSelf>
    using rebind_t = decorated_calculator<OtherSelf>;

    int offset_value() const { return 100 + this->base_::offset_value(); }
};

TEST(base_decorated_with_base_tests, extendable_crtp_base_decorated_with_decorator__self_is_default__ok)
{
    static_assert(meta::CrtpDecorator<offset_factor_decorator>);

    decorated_calculator calculator;
    static_assert(meta::CrtpBase<decorated_calculator<>>);
    static_assert(!meta::CrtpDecorator<decorated_calculator<>>);
    static_assert(std::is_same_v<decorated_calculator<>::self_type, decorated_calculator<>>);
    ASSERT_EQ(calculator.compute(3), 113);
}

template <class Base>
class add_thousand : public Base
{
private:
    using base_ = Base;

public:
    template <class OtherSelf>
    using rebind_t = add_thousand<meta::rebind_t<Base, OtherSelf>>;

    template <meta::CrtpBase OtherBase>
    using rebase_t =
        meta::conditional_rebase_t<Base, add_thousand<OtherBase>, add_thousand<meta::rebase_t<Base, OtherBase>>>;

    int offset_value() const { return 1000 + this->base_::offset_value(); }
};

using add_thousand_decorator = add_thousand<meta::crtp_decorator>;

class final_decorated_calculator
    : public meta::decorate_t<decorated_calculator<>, add_thousand_decorator, final_decorated_calculator>
{
};

TEST(base_decorated_with_base_tests, final_base_decorated_with_decorator__decorated__ok)
{
    static_assert(meta::CrtpDecorator<add_thousand_decorator>);

    final_decorated_calculator calculator;
    static_assert(meta::CrtpBase<final_decorated_calculator>);
    static_assert(!meta::CrtpDecorator<final_decorated_calculator>);
    static_assert(meta::CrtpType<final_decorated_calculator>);
    ASSERT_EQ(calculator.compute(3), 1113);
}
