#ifndef __BOSONVM_MISC_ENUMUTILS_HPP__
#define __BOSONVM_MISC_ENUMUTILS_HPP__

#ifndef NEUTRONTL_CONFIG_USE_WCHAR

/// @brief 序列化键值对
#define BVM_ENUM_SERIALIZE(name)  \
    SerializatingMap::value_type( \
        name,                     \
        ntl::Serialization(ntl::String(#name)))

/// @brief 反序列化键值对
#define BVM_ENUM_DESERIALIZE(name)  \
    DeserializatingMap::value_type( \
        ntl::String(#name),         \
        name)

#else

/// @brief 序列化键值对
#define BVM_ENUM_SERIALIZE(name)  \
    SerializatingMap::value_type( \
        name,                     \
        ntl::String(L#name))

/// @brief 反序列化键值对
#define BVM_ENUM_DESERIALIZE(name)  \
    DeserializatingMap::value_type( \
        ntl::String(L#name),        \
        name)

#endif

#endif
