#ifndef __BOSONVM_INSTRUCTION_NATIVECALLBACK_CPP__
#define __BOSONVM_INSTRUCTION_NATIVECALLBACK_CPP__

#include "NativeCallback.hpp"

namespace bvm
{
    void NativeCallback::operator()(
        BasicState &state,
        const FunctionArguments &arguments) {}

} // namespace bvm

#endif
