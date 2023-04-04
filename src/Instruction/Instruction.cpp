#ifndef __BOSONVM_INSTRUCTION_INSTRUCTION_CPP__
#define __BOSONVM_INSTRUCTION_INSTRUCTION_CPP__

#include "Instruction.hpp"

namespace bvm
{
    Instruction::Instruction(
        const Command::EnumType &command)
        : m_command(command) {}

    Instruction::Instruction(
        const Command::EnumType &command,
        const ntl::Int64 &argument)
        : m_command(command),
          m_argument(argument) {}

    Instruction::Instruction(
        const Command::EnumType &command,
        const CommandFlag::EnumType &flag)
        : m_command(command),
          m_flag(flag) {}

    Instruction::Instruction(
        const Command::EnumType &command,
        const CommandFlag::EnumType &flag,
        const ntl::Int64 &argument)
        : m_command(command),
          m_flag(flag),
          m_argument(argument) {}

    const Command::EnumType &
    Instruction::get_command() const
    {
        return m_command;
    }

    const CommandFlag::EnumType &
    Instruction::get_flag() const
    {
        return m_flag;
    }

    const ntl::Int64 &
    Instruction::get_argument() const
    {
        return m_argument;
    }

} // namespace bvm

namespace ntl
{
    Serialization
    serialize(
        const bvm::Instruction &instruction)
    {
        StringStream sstr;
        sstr << NTL_STRING("cmd:") << bvm::Command::serializating_map.at(instruction.get_command()) << NTL_STRING(",")
             << NTL_STRING("flg:") << instruction.get_flag() << NTL_STRING(",")
             << NTL_STRING("arg:") << instruction.get_argument() << NTL_STRING(",");
        return Serialization(sstr.str());
    }
} // namespace ntl

#endif
