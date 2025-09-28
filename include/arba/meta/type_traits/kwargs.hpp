#pragma once

#include "sequence.hpp"
#include <arba/meta/algorithm/filter_and_make_tuple.hpp>

#include <tuple>
#include <type_traits>

inline namespace arba
{
namespace meta
{

class kwarg_base_
{
    kwarg_base_() {}

    template <class>
    friend class kwarg;
};

template <class Type>
class kwarg;

template <class Type>
    requires std::is_scalar_v<Type>
class kwarg<Type> : public kwarg_base_
{
public:
    kwarg(Type arg) : value_(arg) {}

    inline operator const Type&() const { return value_; }
    inline operator Type&() { return value_; }

    using underlying_type = Type;

private:
    Type value_;
};

template <class Type>
    requires std::is_reference_v<Type>
class kwarg<Type> : public kwarg_base_
{
public:
    kwarg(Type arg) : value_(arg) {}

    kwarg(std::reference_wrapper<std::remove_reference_t<Type>> arg) : value_(static_cast<Type>(arg)) {}

    inline operator const Type() const { return value_; }
    inline operator Type() { return value_; }

    using underlying_type = Type;

private:
    Type value_;
};

template <class Type>
    requires std::is_class_v<Type>
class kwarg<Type> : public Type, public kwarg_base_
{
public:
    using Type::Type;

    using underlying_type = Type;
};

#define ARBA_META_KWARG(Keyword_, Type_)                                                                               \
    class Keyword_ : public ::arba::meta::kwarg<Type_>                                                                 \
    {                                                                                                                  \
    public:                                                                                                            \
        using ::arba::meta::kwarg<Type_>::kwarg;                                                                       \
    }

template <class T, class... Kwargs>
concept Kwarg = (sizeof...(Kwargs) > 0) && (std::is_base_of_v<meta::kwarg_base_, Kwargs> && ...)
                && (std::is_same_v<T, Kwargs> || ...);

template <class... Types>
class kwargs_parser
{
private:
    using tuple_type_ = std::tuple<Types&&...>;

public:
    kwargs_parser(Types&&... args) : t_args_(std::forward_as_tuple(std::forward<Types>(args)...)) {}

    template <class RequestedType>
    decltype(auto) arg_or_default(const RequestedType& default_value) const
    {
        constexpr std::size_t arg_type_idx = decayed_tuple_element_index_v<tuple_type_, RequestedType>;
        if constexpr (arg_type_idx != std::tuple_size_v<tuple_type_>)
        {
            using element_t = std::remove_cvref_t<std::tuple_element_t<arg_type_idx, std::tuple<Types&&...>>>;
            using underlying_type_t = typename element_t::underlying_type;
            return std::forward<underlying_type_t>(std::get<arg_type_idx>(t_args_));
        }
        else
        {
            return default_value;
        }
    }

    template <class RequestedType, typename Callable>
    decltype(auto) arg_or_generate(Callable&& gen_default) const
    {
        constexpr std::size_t arg_type_idx = decayed_tuple_element_index_v<tuple_type_, RequestedType>;
        if constexpr (arg_type_idx != std::tuple_size_v<tuple_type_>)
        {
            using element_t = std::remove_cvref_t<std::tuple_element_t<arg_type_idx, std::tuple<Types&&...>>>;
            using underlying_type_t = typename element_t::underlying_type;
            return std::forward<underlying_type_t>(std::get<arg_type_idx>(t_args_));
        }
        else
        {
            return gen_default();
        }
    }

    decltype(auto) unrecognized_args() const
    {
        auto filter_not_kwargs_ = [](auto&&... args)
        { return filter_and_forward_as_tuple<not_kwarg_t_>(std::forward<decltype(args)>(args)...); };

        return std::apply(filter_not_kwargs_, t_args_);
    }

    template <class Fn, class... Ts>
    decltype(auto) apply_with_unrecognized_args(Fn&& fn, Ts&&... args) const
    {
        return std::apply(std::forward<Fn>(fn),
                          std::tuple_cat(std::forward_as_tuple(std::forward<Ts>(args)...), unrecognized_args()));
    }

private:
    template <class T>
    using not_kwarg_t_ = std::negation<std::is_base_of<kwarg_base_, T>>;

private:
    std::tuple<Types&&...> t_args_;
};

} // namespace meta
} // namespace arba
