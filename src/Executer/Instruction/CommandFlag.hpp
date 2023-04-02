#ifndef __BOSONVM_EXECUTER_COMMANDFLAG_HPP__
#define __BOSONVM_EXECUTER_COMMANDFLAG_HPP__

#include <ntl/NTL.hpp>

namespace bvm
{
    namespace Executer
    {
        /// @brief 命令标志
        namespace CommandFlag
        {
            /// @brief 枚举类型
            using EnumType = ntl::BasicEnumeration<ntl::Int32>;

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

        } // namespace Command

    } // namespace Executer

} // namespace bvm

#endif
