#pragma once

#include <arba/meta/algorithm/concat.hpp>

#include <bit>
#include <format>
#include <functional>
#include <string_view>
#include <type_traits>

inline namespace arba
{
namespace meta
{

enum class enum_conversion
{
    implicit_conversion,
    explicit_conversion,
};

namespace private_
{
template <class BaseType, bool Implicit>
class enumerator_core_;

class enumeration_base_;

// enumerator

class enumerator_base_
{
    constexpr enumerator_base_() {}

    template <class BaseType, bool>
    friend class enumerator_core_;

public:
    constexpr auto operator<=>(const enumerator_base_& other) const noexcept = default;
};

template <class BaseType, bool Implicit>
class enumerator_core_ : public enumerator_base_
{
protected:
    using enumerator_core_type_ = enumerator_core_;

public:
    using value_type = BaseType;
    static constexpr bool implicit = Implicit;

    constexpr enumerator_core_() {}

    constexpr const value_type& value() const noexcept { return value_; }

    constexpr operator value_type() const noexcept
        requires implicit
    {
        return value_;
    }

    constexpr explicit operator value_type() const noexcept
        requires(!implicit)
    {
        return value_;
    }

    constexpr auto operator<=>(const enumerator_core_& other) const noexcept = default;

protected:
    constexpr enumerator_core_(const BaseType& val)
        requires std::is_base_of_v<enumerator_base_, BaseType>
        : value_(val.value())
    {
    }

private:
    consteval enumerator_core_(value_type val) : value_(val) {}
    friend enumeration_base_;

private:
    value_type value_;
};

template <class BaseType>
struct default_enum_type_
{
    static constexpr enum_conversion value = enum_conversion::implicit_conversion;
};

template <class BaseType>
    requires(std::is_base_of_v<enumerator_base_, BaseType>)
struct default_enum_type_<BaseType>
{
    static constexpr enum_conversion value =
        BaseType::implicit ? enum_conversion::implicit_conversion : enum_conversion::explicit_conversion;
};

template <class BaseType, bool Implicit>
struct enumerator_parent_
{
    using type = enumerator_core_<BaseType, Implicit>;
};

template <class BaseType, bool Implicit>
    requires(std::is_base_of_v<enumerator_base_, BaseType>)
struct enumerator_parent_<BaseType, Implicit>
{
    static_assert(Implicit == BaseType::implicit,
                  "enumerator and enumerator::base_type must have the same implicit value.");
    using type = BaseType;
};
}

template <class BaseType, class EnumerationType, enum_conversion EnumType = private_::default_enum_type_<BaseType>::value>
class enumerator : public private_::enumerator_parent_<BaseType, EnumType == enum_conversion::implicit_conversion>::type
{
    using base_ = typename private_::enumerator_parent_<BaseType, EnumType == enum_conversion::implicit_conversion>::type;
    using enumerator_type_ = enumerator;

public:
    using enumeration = EnumerationType;
    using typename base_::value_type;
    using base_type = BaseType;

protected:
    using typename base_::enumerator_core_type_;
    friend private_::enumeration_base_;

public:
    constexpr enumerator() {}
    constexpr enumerator(const base_type& val)
        requires std::is_base_of_v<private_::enumerator_base_, base_type>
        : base_(val)
    {
    }
    consteval enumerator(const enumerator_core_type_& val) : base_(val) {}

    /*constexpr*/ std::string_view name() const noexcept
        requires std::convertible_to<value_type, std::string_view> || requires {
            { enumeration::name(this->value()) } -> std::convertible_to<std::string_view>;
        }
    {
        if constexpr (std::convertible_to<value_type, std::string_view>)
            return static_cast<std::string_view>(this->value());
        else
            return enumeration::name(this->value());
    }

    constexpr std::size_t index() const
        requires (requires {
            { enumeration::index(value_type()) } -> std::convertible_to<std::size_t>;
        })
    {
        return enumeration::index(this->value());
    }
};

template <typename Type>
concept Enumerator = std::is_base_of_v<private_::enumerator_base_, Type> && requires(const Type& arg) {
    typename Type::value_type;
    typename Type::enumeration;
    { arg.value() } -> std::convertible_to<typename Type::value_type>;
};

// enumeration

template <class EnumeratorType, class SelfType>
class enumeration;

namespace private_
{
class enumeration_base_
{
protected:
    template <class EnumeratorType, class SelfType>
    class enumerator_maker
    {
        template <class... ArgsTypes>
        static consteval auto make_(typename EnumeratorType::value_type val, ArgsTypes&&... args)
        {
            return EnumeratorType(typename EnumeratorType::enumerator_core_type_(val),
                                  std::forward<ArgsTypes>(args)...);
        }
        friend enumeration<EnumeratorType, SelfType>;
    };
};

template <class Type>
struct enumeration_parent_
{
    using type = enumeration_base_;
};

template <class EnumeratorType>
    requires(std::is_base_of_v<enumerator_base_, typename EnumeratorType::base_type>)
struct enumeration_parent_<EnumeratorType>
{
    static_assert(std::is_base_of_v<enumeration_base_, typename EnumeratorType::base_type::enumeration>);
    using type = typename EnumeratorType::base_type::enumeration;
};
}

template <class EnumeratorType, class SelfType>
class enumeration : public private_::enumeration_parent_<EnumeratorType>::type
{
    using base_ = typename private_::enumeration_parent_<EnumeratorType>::type;
    using self_ = SelfType;

protected:
    using value_type = typename EnumeratorType::value_type;

public:
    using enumerator = EnumeratorType;
    friend typename enumerator::enumerator_type_;

public:
    static constexpr std::size_t size()
        requires requires {
        { self_::all() };
    }
    {
        constexpr std::size_t all_size = all().size();
        return all_size;
    }

protected:
    template <class... ArgsTypes>
    static consteval enumerator make_enumerator(value_type val, ArgsTypes&&... args)
    {
        return private_::enumeration_base_::enumerator_maker<enumerator, self_>::make_(val, std::forward<ArgsTypes>(args)...);
    }

    static /*constexpr*/ std::string_view name(value_type value) noexcept
        requires requires {
            { self_::all_names() };
            { self_::index(value) };
        }
    {
        const auto& all_names_ = self_::all_names();
        return all_names_.at(self_::index(value));
    }

    static constexpr std::size_t index(const value_type& value)
        requires std::is_integral_v<value_type> || requires {
        { self_::all() };
    }
    {
        if constexpr (std::is_integral_v<value_type>)
        {
            std::size_t idx = value;
            if constexpr (requires {
                              { self_::enumerator_index_offset() } -> std::convertible_to<int>;
                              { self_::enumerator_index_factor() } -> std::convertible_to<int>;
                          })
            {
                idx -= self_::enumerator_index_offset();
                idx /= self_::enumerator_index_factor();
                return idx;
            }
            if constexpr (requires {
                              { self_::enumerator_index_offset() } -> std::convertible_to<int>;
                              { self_::enumerator_is_regular_bit() } -> std::same_as<bool>;
                          })
            {
                static_assert(self_::enumerator_is_regular_bit());
                idx -= self_::enumerator_index_offset();
                idx = std::bit_width(idx);
                return idx;
            }
        }
        if constexpr (requires {
            { self_::all() };
        })
        {
            std::size_t idx = 0;
            for (const auto& item : self_::all())
            {
                if (item.value() == value)
                    return idx;
                ++idx;
            }
        }
        return std::numeric_limits<std::size_t>::max();
    }

public:
    static constexpr decltype(auto) all()
        requires(requires {
            { self_::enumerators.size() } -> std::convertible_to<std::size_t>;
        } && (self_::enumerators.size() > 0))
    {
        if constexpr (requires {
                          { base_::all() };
                      })
        {
            constexpr std::array all_values = concat<enumerator>(base_::all(), self_::enumerators);
            return all_values;
        }
        else
            return static_cast<const decltype(self_::enumerators)&>(self_::enumerators);
    }

    static /*constexpr*/ decltype(auto) all_names()
        requires requires {
            { self_::enumerator_names[0ull] } -> std::convertible_to<std::string_view>;
        }
    {
        if constexpr (requires {
                          { base_::all_names() };
                      })
        {
            static const /*expr*/ std::array all_names_ = concat(base_::all_names(), self_::enumerator_names);
            return static_cast<const decltype(all_names_)&>(all_names_);
        }
        else
            return static_cast<const decltype(self_::enumerator_names)&>(self_::enumerator_names);
    }

    static constexpr std::size_t enumerator_index_offset()
        requires std::is_integral_v<value_type> && requires {
            { self_::all() };
        }
    {
        constexpr auto first_ = all().front().value();
        return first_;
    }

    static constexpr std::size_t enumerator_index_factor()
        requires std::is_integral_v<value_type> && requires {
        { self_::enumerator_index_factor_() };
    } && (self_::enumerator_index_factor_() > 0)
    {
        return self_::enumerator_index_factor_();
    }

    static constexpr std::size_t enumerator_is_regular_bit()
        requires std::unsigned_integral<value_type> && requires {
        { self_::enumerator_is_regular_bit_() };
    } && (self_::enumerator_is_regular_bit_())
    {
        return self_::enumerator_is_regular_bit_();
    }

private:
    static consteval std::size_t enumerator_index_factor_()
        requires requires {
        { self_::all() };
    }
    {
        decltype(auto) all_values = self_::all();
        const std::size_t diff = all_values[1].value() - all_values.front().value();
        auto iter = all_values.begin() + 1, end_iter = all_values.end();
        if (iter == end_iter)
            return 0;
        for (auto next_iter = iter + 1; next_iter != end_iter; iter = next_iter, ++next_iter)
        {
            const std::size_t cur_diff = next_iter->value() - iter->value();
            if (cur_diff != diff)
                return 0;
        }
        return diff;
    }

    static consteval bool enumerator_is_regular_bit_()
        requires requires {
        { self_::all() };
    }
    {
        decltype(auto) all_values = self_::all();
        if (const value_type value = all_values.front().value(); !std::has_single_bit(value))
            return false;
        for (auto prev = all_values.cbegin(), iter = prev + 1, end_iter = all_values.cend(); iter != end_iter; prev = iter, ++iter)
        {
            const value_type value = iter->value();
            if (!std::has_single_bit(value))
                return false;
            if (value == (prev->value() << 1))
                return false;

        }
        return true;
    }
};

} // namespace meta
} // namespace arba

template <::arba::meta::Enumerator EnumeratorType>
    requires requires(const EnumeratorType& arg) {
        { std::hash<typename EnumeratorType::value_type>{}(arg.value()) } -> std::same_as<std::size_t>;
    }
struct std::hash<EnumeratorType> : private std::hash<typename EnumeratorType::value_type>
{
private:
    using base_ = std::hash<typename EnumeratorType::value_type>;

public:
    inline std::size_t operator()(const EnumeratorType& arg) const noexcept
    {
        return static_cast<const base_&>(*this)(arg.value());
    }
};

template <class CharT, ::arba::meta::Enumerator EnumeratorType>
    requires requires(const EnumeratorType& arg) {
        { arg.name() } -> std::same_as<std::string_view>;
    } || requires(const EnumeratorType& arg) {
        { std::format("{}", arg.value()) };
    }
struct std::formatter<EnumeratorType, CharT> : public std::formatter<std::string_view, CharT>
{
private:
    static constexpr bool has_name()
    {
        return requires(const EnumeratorType& arg) {
            { arg.name() } -> std::same_as<std::string_view>;
        };
    }

    enum fmt_chars_ : char
    {
        name_ch = 'n',
        value_ch = 'v',
        full_ch = 'f',
    };

public:
    template <class FormatParseContext>
    constexpr auto parse(FormatParseContext& ctx)
    {
        auto iter = ctx.begin();
        if (iter == ctx.end())
            return iter;

        const char ch = *iter;
        if (ch == '}')
        {
            if constexpr (has_name())
                fmt_ = name_ch;
            else
                fmt_ = value_ch;
            return iter;
        }

        if (ch == value_ch)
        {
            fmt_ = ch;
            return ++iter;
        }
        if constexpr (has_name())
        {
            if (ch == name_ch)
            {
                fmt_ = ch;
                return ++iter;
            }
            if constexpr (requires(const EnumeratorType& arg) {
                              { std::format("{}", arg.value()) };
                          })
            {
                if (ch == full_ch)
                {
                    fmt_ = ch;
                    return ++iter;
                }
            }
        }
        return iter; // expect `}` at this position, otherwise, it's error! exception!
    }

    template <class FormatContext>
    auto format(const EnumeratorType& arg, FormatContext& ctx) const
    {
        switch (fmt_)
        {
        case name_ch:
            return std::formatter<std::string_view, CharT>::format(arg.name(), ctx);
        case value_ch:
            return std::format_to(ctx.out(), "{}", arg.value());
        case full_ch:
            return std::format_to(ctx.out(), "({}={})", arg.name(), arg.value());
        }
        throw std::runtime_error(std::format("Unknown format: '{}'", fmt_));
    }

private:
    char fmt_ = '?';
};
