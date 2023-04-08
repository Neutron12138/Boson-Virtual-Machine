#ifndef __BOSONVM_INSTRUCTION_COMMAND_HPP__
#define __BOSONVM_INSTRUCTION_COMMAND_HPP__

#include <map>
#include <ntl/NTL.hpp>
#include "../Misc/EnumUtils.hpp"

namespace bvm
{
    /// @brief 命令
    namespace Command
    {
        /// @brief 枚举类型
        using EnumType = ntl::BasicEnumeration<ntl::Int32>;

        /// @brief 序列化映射表
        using SerializatingMap = std::map<EnumType, ntl::Serialization>;

        /// @brief 反序列化映射表
        using DeserializatingMap = std::map<ntl::String, EnumType>;

        //
        //
        //

        /// @brief 无操作
        static const EnumType None = EnumType(0);

        /// @brief 将值放入temp stack栈顶
        static const EnumType Load = EnumType(1);

        /// @brief 将值从temp stack栈顶移除
        static const EnumType Remove = EnumType(2);

        /// @brief 将值从temp stack出栈并保存到内存中
        static const EnumType Store = EnumType(3);

        /// @brief 将值移到temp stack栈顶
        static const EnumType Move = EnumType(4);

        /// @brief 调用本地代码
        static const EnumType NativeCall = EnumType(5);

        /// @brief 新建临时变量到temp stack
        static const EnumType MakeTemp = EnumType(6);

        /// @brief 调用一个函数
        static const EnumType Call = EnumType(7);

        /// @brief 添加一个函数调用参数
        static const EnumType CallPush = EnumType(8);

        //
        //
        //

        /// @brief 序列化映射表
        static const SerializatingMap serializating_map = SerializatingMap{
            BVM_ENUM_SERIALIZE(None),
            BVM_ENUM_SERIALIZE(Load),
            BVM_ENUM_SERIALIZE(Remove),
            BVM_ENUM_SERIALIZE(Store),
            BVM_ENUM_SERIALIZE(Move),
            BVM_ENUM_SERIALIZE(NativeCall),
            BVM_ENUM_SERIALIZE(MakeTemp),
            BVM_ENUM_SERIALIZE(Call),
            BVM_ENUM_SERIALIZE(CallPush),
        };

        //
        //
        //

        /// @brief 反序列化映射表
        static const DeserializatingMap deserializating_map = DeserializatingMap{
            BVM_ENUM_DESERIALIZE(None),
            BVM_ENUM_DESERIALIZE(Load),
            BVM_ENUM_DESERIALIZE(Remove),
            BVM_ENUM_DESERIALIZE(Store),
            BVM_ENUM_DESERIALIZE(Move),
            BVM_ENUM_DESERIALIZE(NativeCall),
            BVM_ENUM_DESERIALIZE(MakeTemp),
            BVM_ENUM_DESERIALIZE(Call),
            BVM_ENUM_DESERIALIZE(CallPush),
        };

    } // namespace Command

} // namespace bvm

#endif
