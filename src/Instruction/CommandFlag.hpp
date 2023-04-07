#ifndef __BOSONVM_INSTRUCTION_COMMANDFLAG_HPP__
#define __BOSONVM_INSTRUCTION_COMMANDFLAG_HPP__

#include <map>
#include <ntl/NTL.hpp>
#include "../Misc/EnumUtils.hpp"

namespace bvm
{
    /// @brief 命令标志
    namespace CommandFlag
    {
        /// @brief 枚举类型
        using EnumType = ntl::BasicEnumeration<ntl::Int16>;

        /// @brief 序列化映射表
        using SerializatingMap = std::map<EnumType, ntl::Serialization>;

        /// @brief 反序列化映射表
        using DeserializatingMap = std::map<ntl::String, EnumType>;

        //
        //
        //

        /// @brief 无
        static const EnumType None = EnumType(0);

        //
        //
        //

        /// @brief 以字节模式操作
        static const EnumType Byte = EnumType(1);

        /// @brief 以字模式操作
        static const EnumType Word = EnumType(2);

        /// @brief 以双字模式操作
        static const EnumType DWord = EnumType(3);

        /// @brief 以四字模式操作
        static const EnumType QWord = EnumType(4);

        //
        //
        //

        /// @brief AX寄存器
        static const EnumType RAX = EnumType(5);

        /// @brief BX寄存器
        static const EnumType RBX = EnumType(6);

        /// @brief CX寄存器
        static const EnumType RCX = EnumType(7);

        /// @brief DX寄存器
        static const EnumType RDX = EnumType(8);

        /// @brief 函数变量
        static const EnumType Variables = EnumType(9);

        /// @brief 函数参数
        static const EnumType Arguments = EnumType(10);

        /// @brief 静态变量
        static const EnumType StaticVariables = EnumType(11);

        /// @brief 全局变量
        static const EnumType GlobalVariables = EnumType(12);

        /// @brief 堆
        static const EnumType Heap = EnumType(13);

        /// @brief 全局栈
        static const EnumType GlobalStack = EnumType(14);

        /// @brief 统一变量
        static const EnumType Uniforms = EnumType(15);

        //
        //
        //

        /// @brief 序列化映射表
        static const SerializatingMap serializating_map = SerializatingMap{
            BVM_ENUM_SERIALIZE(None),
            BVM_ENUM_SERIALIZE(Byte),
            BVM_ENUM_SERIALIZE(Word),
            BVM_ENUM_SERIALIZE(DWord),
            BVM_ENUM_SERIALIZE(QWord),
            BVM_ENUM_SERIALIZE(RAX),
            BVM_ENUM_SERIALIZE(RBX),
            BVM_ENUM_SERIALIZE(RCX),
            BVM_ENUM_SERIALIZE(RDX),
            BVM_ENUM_SERIALIZE(Variables),
            BVM_ENUM_SERIALIZE(Arguments),
            BVM_ENUM_SERIALIZE(StaticVariables),
            BVM_ENUM_SERIALIZE(GlobalVariables),
            BVM_ENUM_SERIALIZE(Heap),
            BVM_ENUM_SERIALIZE(GlobalStack),
            BVM_ENUM_SERIALIZE(Uniforms),

        };

        //
        //
        //

        /// @brief 反序列化映射表
        static const DeserializatingMap deserializating_map = DeserializatingMap{
            BVM_ENUM_DESERIALIZE(None),
            BVM_ENUM_DESERIALIZE(Byte),
            BVM_ENUM_DESERIALIZE(Word),
            BVM_ENUM_DESERIALIZE(DWord),
            BVM_ENUM_DESERIALIZE(QWord),
            BVM_ENUM_DESERIALIZE(RAX),
            BVM_ENUM_DESERIALIZE(RBX),
            BVM_ENUM_DESERIALIZE(RCX),
            BVM_ENUM_DESERIALIZE(RDX),
            BVM_ENUM_DESERIALIZE(Variables),
            BVM_ENUM_DESERIALIZE(Arguments),
            BVM_ENUM_DESERIALIZE(StaticVariables),
            BVM_ENUM_DESERIALIZE(GlobalVariables),
            BVM_ENUM_DESERIALIZE(Heap),
            BVM_ENUM_DESERIALIZE(GlobalStack),
            BVM_ENUM_DESERIALIZE(Uniforms),

        };

    } // namespace Command

} // namespace bvm

#endif
