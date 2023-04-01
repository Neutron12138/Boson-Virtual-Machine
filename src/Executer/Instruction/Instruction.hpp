#ifndef __BOSONVM_EXECUTER_INSTRUCTION_HPP__
#define __BOSONVM_EXECUTER_INSTRUCTION_HPP__

#include <vector>
#include <ntl/NTL.hpp>
#include "Command.hpp"
#include "CommandFlag.hpp"

namespace bvm
{
    namespace Executer
    {
        /// @brief 指令
        class NTL_ALIGN Instruction : public ntl::BasicObject
        {
        public:
            using SelfType = Instruction;
            using ParentType = BasicObject;

        protected:
            /// @brief 指令
            Command::EnumType m_command = Command::None;

            /// @brief 标志
            CommandFlag::EnumType m_flag = CommandFlag::None;

            /// @brief 参数
            ntl::Int64 m_argument = 0;

        public:
            Instruction() = default;
            explicit Instruction(
                const Command::EnumType &command);
            explicit Instruction(
                const Command::EnumType &command,
                const ntl::Int64 &argument);
            explicit Instruction(
                const Command::EnumType &command,
                const CommandFlag::EnumType &flag);
            explicit Instruction(
                const Command::EnumType &command,
                const CommandFlag::EnumType &flag,
                const ntl::Int64 &argument);
            explicit Instruction(const SelfType &from) = default;
            ~Instruction() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;

        public:
            const Command::EnumType &get_command() const;
            const CommandFlag::EnumType &get_flag() const;
            const ntl::Int64 &get_argument() const;
        };

        /// @brief 指令容器
        using InstructionContainer = std::vector<Instruction>;

    } // namespace Executer

} // namespace bvm

namespace ntl
{
    Serialization serialize(const bvm::Executer::Instruction &instruction);

} // namespace ntl

#endif