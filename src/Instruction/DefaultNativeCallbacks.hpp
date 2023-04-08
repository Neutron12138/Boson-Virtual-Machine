#ifndef __BOSONVM_INSTRUCTION_DEFAULTNATIVECALLBACKS_HPP__
#define __BOSONVM_INSTRUCTION_DEFAULTNATIVECALLBACKS_HPP__

#include "../Instruction/NativeCallback.hpp"

namespace bvm
{
    namespace DefaultNativeCallbacks
    {
        enum PrintEnum
        {
            StdOut = 0,
            StdLog,
            StdError,
            File,

            SingleChar = 0,
            WideChar,
            Number,
        };

        void print(BasicState &state, FunctionArguments arguments);

    } // namespace DefaultNativeCallbacks

} // namespace bvm

#endif
