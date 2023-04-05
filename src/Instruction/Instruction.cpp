#ifndef __BOSONVM_INSTRUCTION_INSTRUCTION_CPP__
#define __BOSONVM_INSTRUCTION_INSTRUCTION_CPP__

#include "Instruction.hpp"

namespace ntl
{
    Serialization
    serialize(
        const bvm::Instruction &instruction)
    {
        StringStream sstr;
        sstr << NTL_STRING("cmd:") << bvm::Command::serializating_map.at(instruction.command) << NTL_STRING(",")
             << NTL_STRING("flg:") << instruction.flag0 << NTL_STRING(",")
             << NTL_STRING("arg:") << instruction.argument << NTL_STRING(",");
        return Serialization(sstr.str());
    }
} // namespace ntl

#endif
