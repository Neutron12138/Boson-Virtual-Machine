#ifndef __BOSONVM_INSTRUCTION_DEFAULTNATIVECALLBACKS_HPP__
#define __BOSONVM_INSTRUCTION_DEFAULTNATIVECALLBACKS_HPP__

#include "../Instruction/NativeCallback.hpp"

namespace bvm
{
    namespace DefaultNativeCallbacks
    {
        void print(BasicState &state, const FunctionArguments &arguments);

    } // namespace DefaultNativeCallbacks

} // namespace bvm

#endif
