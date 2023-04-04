#ifndef __BOSONVM_INSTRUCTION_COMMANDFLAG_HPP__
#define __BOSONVM_INSTRUCTION_COMMANDFLAG_HPP__

#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 命令标志
    namespace CommandFlag
    {
        /// @brief 枚举类型
        using EnumType = ntl::BasicEnumeration<ntl::Int32>;

        /// @brief 序列化映射表
        using SerializatingMap = std::map<EnumType, ntl::Serialization>;

        /// @brief 反序列化映射表
        using DeserializatingMap = std::map<ntl::Serialization, EnumType>;

        /// @brief 无
        static const EnumType None = EnumType(0);

        /// @brief 以字节模式操作
        static const EnumType Byte = EnumType(1);

        /// @brief 以字模式操作
        static const EnumType Word = EnumType(2);

        /// @brief 以双字模式操作
        static const EnumType DWord = EnumType(3);

        /// @brief 以四字模式操作
        static const EnumType QWord = EnumType(4);

        /// @brief 序列化映射表
        static const SerializatingMap serializating_map = SerializatingMap{
            SerializatingMap::value_type(
                None,
                NTL_STRING("None")),

            SerializatingMap::value_type(
                Byte,
                NTL_STRING("Byte")),

            SerializatingMap::value_type(
                Word,
                NTL_STRING("Word")),

            SerializatingMap::value_type(
                DWord,
                NTL_STRING("DWord")),

            SerializatingMap::value_type(
                QWord,
                NTL_STRING("QWord")),
        };

        /// @brief 反序列化映射表
        static const DeserializatingMap deserializating_map = DeserializatingMap{
            SerializatingMap::value_type(
                NTL_STRING("None"),
                None),

            SerializatingMap::value_type(
                NTL_STRING("Byte"),
                Byte),

            SerializatingMap::value_type(
                NTL_STRING("Word"),
                Word),

            SerializatingMap::value_type(
                NTL_STRING("DWord"),
                DWord),

            SerializatingMap::value_type(
                NTL_STRING("QWord"),
                QWord),
        };

    } // namespace Command

} // namespace bvm

#endif
