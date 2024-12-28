#pragma once

inline namespace arba
{
namespace meta
{

// associated_type

template <class TagType, class ObservedType>
struct associated_type;

template <class TagType, class ObservedType>
using associated_type_t = typename associated_type<TagType, ObservedType>::type;

// associated_type_or_default

template <class TagType, class ObservedType, class OrType>
struct associated_type_or_default
{
    using type = OrType;
};

template <class TagType, class ObservedType, class OrType>
    requires requires { typename associated_type_t<TagType, ObservedType>; }
struct associated_type_or_default<TagType, ObservedType, OrType>
{
    using type = associated_type_t<TagType, ObservedType>;
};

template <class TagType, class ObservedType, class OrType>
using associated_type_or_default_t = typename associated_type_or_default<TagType, ObservedType, OrType>::type;
} // namespace meta
} // namespace arba

// macro define helper

#define ARBA_META_DEFINE_ASSOCIATED_TYPE(TagType, ObservedType, AssociatedType)                                        \
    template <>                                                                                                        \
    struct arba::meta::associated_type<TagType, ObservedType>                                                          \
    {                                                                                                                  \
        using type = AssociatedType;                                                                                   \
    };

#ifndef META_DEFINE_ASSOCIATED_TYPE
#define META_DEFINE_ASSOCIATED_TYPE(TagType, ObservedType, AssociatedType_)                                            \
    ARBA_META_DEFINE_ASSOCIATED_TYPE(TagType, ObservedType, AssociatedType_)
#else
#if defined(__GNUC__) || defined(__GNUG__) || defined(_MSC_VER) || defined(__clang__)
#pragma message "META_DEFINE_ASSOCIATED_TYPE already exists. You must use ARBA_META_DEFINE_ASSOCIATED_TYPE."
#endif
#endif
