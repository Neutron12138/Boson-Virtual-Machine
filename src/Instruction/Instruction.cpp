#ifndef __BOSONVM_INSTRUCTION_INSTRUCTION_CPP__
#define __BOSONVM_INSTRUCTION_INSTRUCTION_CPP__

#include "Instruction.hpp"

namespace bvm
{
    Instruction::Instruction(Command::EnumType a_command,
                             const Value &a_argument)
        : command(a_command),
          argument(a_argument) {}

    Instruction::Instruction(Command::EnumType a_command,
                             CommandFlag::EnumType a_flag0,
                             const Value &a_argument)
        : command(a_command),
          flag0(a_flag0),
          argument(a_argument) {}

    Instruction::Instruction(Command::EnumType a_command,
                             CommandFlag::EnumType a_flag0,
                             CommandFlag::EnumType a_flag1,
                             const Value &a_argument)
        : command(a_command),
          flag0(a_flag0),
          flag1(a_flag1),
          argument(a_argument) {}

} // namespace bvm

namespace ntl
{
    Serialization
    serialize(
        const bvm::Instruction &instruction)
    {
        StringStream sstr;
        sstr << NTL_STRING("command:") << bvm::Command::serializating_map.at(instruction.command) << NTL_STRING(",\t")
             << NTL_STRING("flag0:") << bvm::CommandFlag::serializating_map.at(instruction.flag0) << NTL_STRING(",\t")
             << NTL_STRING("flag1:") << bvm::CommandFlag::serializating_map.at(instruction.flag1) << NTL_STRING(",\t")
             << NTL_STRING("argument:") << instruction.argument;
        return Serialization(sstr.str());
    }
} // namespace ntl

#endif
