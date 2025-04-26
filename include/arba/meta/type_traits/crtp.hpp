#pragma once

#include "type_or_default.hpp"

#include <type_traits>

inline namespace arba
{
namespace meta
{

// CrtpBase:

template <class SelfType>
class crtp_base;

template <>
class crtp_base<void>
{
protected:
    template <class>
    using rebase_t = crtp_base;
};

template <class SelfType>
    requires(std::is_class_v<SelfType>)
class crtp_base<SelfType> : public crtp_base<void>
{
public:
    using self_type = SelfType;

protected:
    [[nodiscard]] inline const self_type& self() const noexcept { return static_cast<const self_type&>(*this); }
    [[nodiscard]] inline self_type& self() noexcept { return static_cast<self_type&>(*this); }
};

template <class Type>
concept CrtpBase = std::is_base_of_v<crtp_base<void>, Type>;

// CrtpDecorator:

class crtp_decorator
{
protected:
    template <class>
    using rebind_t = crtp_decorator;

    template <class>
    using rebase_t = crtp_decorator;
};

template <class Type>
concept CrtpDecorator = std::is_base_of_v<crtp_decorator, Type>;

// CrtpType:

template <class Type>
concept CrtpType = CrtpBase<Type> || CrtpDecorator<Type>;

// helpers:

template <class Base, class OtherType>
using rebind_t = typename Base::template rebind_t<OtherType>;

template <class Base, class OtherBaseType>
using rebase_t = typename Base::template rebase_t<OtherBaseType>;

template <CrtpDecorator Base, CrtpBase RebasedType, CrtpType RecRebasedType>
using conditional_rebase_t = std::conditional_t<std::is_same_v<Base, crtp_decorator>, RebasedType, RecRebasedType>;

template <CrtpBase Base, CrtpDecorator Decorator, class OtherSelf>
struct decorate
{
    using type = rebind_t<rebase_t<Decorator, Base>, OtherSelf>;
};

template <CrtpBase Base, CrtpDecorator Decorator>
struct decorate<Base, Decorator, default_t>
{
    using type = rebase_t<Decorator, Base>;
};

template <CrtpBase Base, class OtherSelf>
struct decorate<Base, crtp_decorator, OtherSelf>
{
    using type = rebind_t<Base, OtherSelf>;
};

template <CrtpBase Base>
struct decorate<Base, crtp_decorator, default_t>
{
    using type = Base;
};

template <CrtpBase Base, CrtpDecorator Decorator, class OtherSelf = default_t>
using decorate_t = typename decorate<Base, Decorator, OtherSelf>::type;

} // namespace meta
} // namespace arba
