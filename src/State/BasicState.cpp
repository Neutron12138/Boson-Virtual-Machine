#ifndef __BOSONVM_STATE_BASICSTATE_CPP__
#define __BOSONVM_STATE_BASICSTATE_CPP__

#include "BasicState.hpp"

namespace bvm
{
    BasicState::BasicState(
        const InstructionManager &manager)
        : m_instruction_manager(manager) {}

    BasicState::BasicState(
        const InstructionManager &manager,
        const GlobalMemory &memory)
        : m_instruction_manager(manager),
          m_global_memory(memory) {}

    const InstructionManager &
    BasicState::get_instruction_manager() const
    {
        return m_instruction_manager;
    }

    const NativeCallbackManager &
    BasicState::get_native_manager() const
    {
        return m_native_manager;
    }

    const FunctionCallStack &
    BasicState::get_call_stack() const
    {
        return m_call_stack;
    }

    const GlobalMemory &
    BasicState::get_global_memory() const
    {
        return m_global_memory;
    }

    BasicState::Status
    BasicState::get_status() const
    {
        return m_status;
    }

    bool
    BasicState::is_call_stack_empty() const
    {
        return m_call_stack.is_empty();
    }

    FunctionArguments &
    BasicState::get_global_stack()
    {
        return m_global_memory.global_stack;
    }

    Register &
    BasicState::get_registers()
    {
        return m_global_memory.registers;
    }

    typename BasicState::SelfType &
    BasicState::add_function(
        ntl::SizeT index,
        const InstructionContainer &instructions)
    {
        m_instruction_manager.add_item(index, instructions);
        return *this;
    }

    typename BasicState::SelfType &
    BasicState::add_function(
        ntl::SizeT index,
        const NativeCallback &callback)
    {
        m_native_manager.add_item(index, callback);
        return *this;
    }

    typename BasicState::SelfType &
    BasicState::call_function(
        ntl::SizeT index,
        const FunctionArguments arguments)
    {
        m_call_stack.push(
            Function(
                m_instruction_manager.get_item(index),
                arguments));
        return *this;
    }

    typename BasicState::SelfType &
    BasicState::abort_current_function(
        std::optional<ntl::SizeT> result)
    {
        m_call_stack.pop();
        if (result.has_value())
            m_global_memory.registers.rax = *result;
        return *this;
    }

    typename BasicState::SelfType &
    BasicState::abort_self()
    {
        m_status = Status::Aborted;
        return *this;
    }

    typename BasicState::SelfType &
    BasicState::execute()
    {
        if (m_status == Status::Stopped)
            throw ntl::RuntimeException(
                NTL_STRING("The state not started, unable to execute"),
                NTL_STRING("typename BasicState::SelfType &BasicState::execute()"));
        else if (m_status == Status::Aborted)
            throw ntl::RuntimeException(
                NTL_STRING("The state has been aborted and cannot continue execution"),
                NTL_STRING("typename BasicState::SelfType &BasicState::execute()"));

        return *this;
    }

    typename BasicState::SelfType &
    BasicState::run()
    {
        if (m_status == Status::Aborted)
            throw ntl::RuntimeException(
                NTL_STRING("The state has been aborted and cannot start"),
                NTL_STRING("typename BasicState::SelfType &BasicState::run()"));

        m_status = Status::Running;

        return *this;
    }

    typename BasicState::SelfType &
    BasicState::stop()
    {
        if (m_status != Status::Aborted)
            m_status = Status::Stopped;

        return *this;
    }

    void
    BasicState::execute_none(
        const Instruction &instruction) {}

    void
    BasicState::execute_load(
        const Instruction &instruction)
    {
    }

    void
    BasicState::execute_remove(
        const Instruction &instruction)
    {
    }

    void
    BasicState::execute_store(
        const Instruction &instruction)
    {
    }

    void
    BasicState::execute_move(
        const Instruction &instruction)
    {
    }

    void
    BasicState::execute_native_call(
        const Instruction &instruction)
    {
    }

} // namespace bvm

#endif
