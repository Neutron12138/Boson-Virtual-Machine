#ifndef __BOSONVM_EXECUTER_COMMAND_HPP__
#define __BOSONVM_EXECUTER_COMMAND_HPP__

#include <map>
#include <ntl/NTL.hpp>

namespace bvm
{
    namespace Executer
    {
        /// @brief 命令
        namespace Command
        {
            /// @brief 枚举类型
            using EnumType = ntl::BasicEnumeration<ntl::Int32>;

            /// @brief 序列化映射表
            using SerializatingMap = std::map<EnumType, ntl::Serialization>;

            /// @brief 反序列化映射表
            using DeserializatingMap = std::map<ntl::Serialization, EnumType>;

            /// @brief 无操作
            static const EnumType None = EnumType(0);

            /// @brief 将值放入temp stack栈顶
            static const EnumType Load = EnumType(1);

            /// @brief 将值从temp stack栈顶移除
            static const EnumType Remove = EnumType(2);

            /// @brief 将值从temp stack出栈并保存到内存中
            static const EnumType Store = EnumType(3);

            /// @brief 将temp stack的栈顶替换
            static const EnumType Move = EnumType(4);

            /// @brief 序列化映射表
            static const SerializatingMap serializating_map = SerializatingMap{
                SerializatingMap::value_type(
                    None,
                    NTL_STRING("None")),

                SerializatingMap::value_type(
                    Load,
                    NTL_STRING("Load")),

                SerializatingMap::value_type(
                    Remove,
                    NTL_STRING("Remove")),

                SerializatingMap::value_type(
                    Store,
                    NTL_STRING("Store")),

                SerializatingMap::value_type(
                    Move,
                    NTL_STRING("Move")),
            };

        } // namespace Command

    } // namespace Executer

} // namespace bvm

#endif
