#ifndef __BOSONVM_MEMORY_REGISTERS_CPP__
#define __BOSONVM_MEMORY_REGISTERS_CPP__

#include "Registers.hpp"

namespace ntl
{
    ntl::Serialization
    serialize(
        const bvm::Registers &registers)
    {
        ntl::StringStream sstr;
        sstr << NTL_STRING("rax:") << registers.rax.qword << NTL_STRING(",\t")
             << NTL_STRING("rbx:") << registers.rbx.qword << NTL_STRING(",\t")
             << NTL_STRING("rcx:") << registers.rcx.qword << NTL_STRING(",\t")
             << NTL_STRING("rdx:") << registers.rdx.qword;
        return ntl::Serialization(sstr.str());
    }

} // namespace ntl

#endif
