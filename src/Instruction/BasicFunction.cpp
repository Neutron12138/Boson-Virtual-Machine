#ifndef __BOSONVM_INSTRUCTION_BASICFUNCTION_CPP__
#define __BOSONVM_INSTRUCTION_BASICFUNCTION_CPP__

#include "BasicFunction.hpp"

namespace bvm
{
    BasicFunction::BasicFunction(
        const FunctionArguments &arguments)
        : m_arguments(arguments) {}

    const FunctionArguments &
    BasicFunction::get_arguments() const
    {
        return m_arguments;
    }

} // namespace bvm

#endif
