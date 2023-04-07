#ifndef __BOSONVM_INSTRUCTION_FUNCTION_CPP__
#define __BOSONVM_INSTRUCTION_FUNCTION_CPP__

#include "Function.hpp"

namespace bvm
{
    Function::Function(
        const InstructionContainer &instructions)
        : BasicFunction(),
          m_instructions(instructions) {}

    Function::Function(
        const InstructionContainer &instructions,
        const MemoryStack &arguments)
        : BasicFunction(arguments),
          m_instructions(instructions) {}

    const InstructionContainer &
    Function::get_instructions() const
    {
        return m_instructions;
    }

    const MemoryManager &
    Function::get_variables() const
    {
        return m_variables;
    }

    const MemoryStack &
    Function::get_temp() const
    {
        return m_temp;
    }

    ntl::SizeT
    Function::get_position() const
    {
        return m_position;
    }

    ntl::SizeT
    Function::size() const
    {
        return m_instructions.size();
    }

    bool
    Function::is_end() const
    {
        return m_position >= size();
    }

    const Instruction &
    Function::get_instruction() const
    {
        try
        {
            const Instruction &result = m_instructions.at(m_position);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("const Instruction &Function::get_instruction() const"));
        }
    }

    typename Function::SelfType &
    Function::forward(ntl::SizeT offset)
    {
        m_position -= offset;
        return *this;
    }

    typename Function::SelfType &
    Function::backward(ntl::SizeT offset)
    {
        m_position += offset;
        return *this;
    }

} // namespace bvm

#endif
