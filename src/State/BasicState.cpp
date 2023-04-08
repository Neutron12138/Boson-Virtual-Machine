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

    const FunctionArguments &
    BasicState::get_call_arguments() const
    {
        return m_call_arguments;
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

    Registers &
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
    BasicState::add_callback(
        ntl::SizeT index,
        NativeCallback callback)
    {
        m_native_manager.add_item(index, callback);
        return *this;
    }

    typename BasicState::SelfType &
    BasicState::call_function(
        ntl::SizeT index,
        const FunctionArguments &arguments)
    {
        try
        {
            m_call_stack.push(
                Function(
                    m_instruction_manager.get_item(index),
                    arguments));
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename BasicState::SelfType &BasicState::call_function(ntl::SizeT index,const FunctionArguments &arguments)"));
        }

        return *this;
    }

    typename BasicState::SelfType &
    BasicState::call_callback(
        ntl::SizeT index,
        const FunctionArguments &arguments)
    {
        try
        {
            m_native_manager.get_item(index)(*this, arguments);
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename BasicState::SelfType &BasicState::call_callback(ntl::SizeT index,const FunctionArguments &arguments)"));
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename BasicState::SelfType &BasicState::call_callback(ntl::SizeT index,const FunctionArguments &arguments)"));
        }
        catch (const std::exception &exception)
        {
            throw ntl::Exception(
                exception,
                NTL_STRING("typename BasicState::SelfType &BasicState::call_callback(ntl::SizeT index,const FunctionArguments &arguments)"));
        }

        return *this;
    }

    typename BasicState::SelfType &
    BasicState::abort_current_function(
        std::optional<Memory> result)
    {
        if (m_call_stack.size() > 0)
        {
            m_call_stack.pop();
            if (result.has_value())
                m_global_memory.global_stack.push(*result);
        }

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

        try
        {
            execute(get_current_instruction());
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename BasicState::SelfType &BasicState::execute()"));
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename BasicState::SelfType &BasicState::execute()"));
        }

        return *this;
    }

    typename BasicState::SelfType &
    BasicState::execute(
        const Instruction &instruction)
    {
        const Command::EnumType &command = instruction.command;
        const CommandFlag::EnumType &flag0 = instruction.flag0;
        const CommandFlag::EnumType &flag1 = instruction.flag1;
        const ntl::Int64 &argument = instruction.argument;

        if (command == Command::None)
            execute_none();
        else if (command == Command::Load)
            execute_load(flag0, flag1, argument);
        else if (command == Command::Remove)
            execute_remove();
        else if (command == Command::Store)
            execute_store(flag1, argument);
        else if (command == Command::Move)
            execute_move(flag0, flag1, argument, m_global_memory.registers.rax);
        else if (command == Command::NativeCall)
            execute_native_call(argument);
        else if (command == Command::MakeTemp)
            execute_make_temp(argument);
        else if (command == Command::Call)
            execute_call(argument);
        else if (command == Command::CallPush)
            execute_call_push();

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

    Function &
    BasicState::get_current_function()
    {
        try
        {
            return m_call_stack.top();
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("Function &BasicState::get_current_function()"));
        }
    }

    const Function &
    BasicState::get_current_function() const
    {
        try
        {
            return m_call_stack.top();
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("const Function &BasicState::get_current_function() const"));
        }
    }

    const Instruction &
    BasicState::get_current_instruction() const
    {
        try
        {
            return get_current_function().get_instruction();
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("const Instruction &BasicState::get_current_instruction() const"));
        }
    }

    void
    BasicState::push_register_to_temp(
        Function &function,
        CommandFlag::EnumType flag0,
        CommandFlag::EnumType flag1)
    {
        auto push = [&](const Value &reg)
        {
            if (flag0 == CommandFlag::Byte)
                function.get_temp().push(Memory().set(reg.byte));
            else if (flag0 == CommandFlag::Word)
                function.get_temp().push(Memory().set(reg.word));
            else if (flag0 == CommandFlag::DWord)
                function.get_temp().push(Memory().set(reg.dword));
            else if (flag0 == CommandFlag::QWord)
                function.get_temp().push(Memory().set(reg.qword));
        };

        if (flag1 == CommandFlag::RAX)
            push(m_global_memory.registers.rax);
        else if (flag1 == CommandFlag::RBX)
            push(m_global_memory.registers.rbx);
        else if (flag1 == CommandFlag::RCX)
            push(m_global_memory.registers.rcx);
        else if (flag1 == CommandFlag::RDX)
            push(m_global_memory.registers.rdx);
    }

    void
    BasicState::push_value_to_temp(
        Function &function,
        CommandFlag::EnumType flag0,
        const Value &argument)
    {
        if (flag0 == CommandFlag::Byte)
            function.get_temp().push(Memory().set(argument.byte));
        else if (flag0 == CommandFlag::Word)
            function.get_temp().push(Memory().set(argument.word));
        else if (flag0 == CommandFlag::DWord)
            function.get_temp().push(Memory().set(argument.dword));
        else if (flag0 == CommandFlag::QWord)
            function.get_temp().push(Memory().set(argument.qword));
    }

    void
    BasicState::move_to_register(
        CommandFlag::EnumType flag1,
        const Value &argument)
    {
        if (flag1 == CommandFlag::RAX)
            m_global_memory.registers.rax.qword = argument;
        else if (flag1 == CommandFlag::RBX)
            m_global_memory.registers.rbx.qword = argument;
        else if (flag1 == CommandFlag::RCX)
            m_global_memory.registers.rcx.qword = argument;
        else if (flag1 == CommandFlag::RDX)
            m_global_memory.registers.rdx.qword = argument;
    }

    void BasicState::execute_none() { get_current_function().backward(); }

    void
    BasicState::execute_load(
        CommandFlag::EnumType flag0,
        CommandFlag::EnumType flag1,
        const Value &argument)
    {
        Function &function = get_current_function();

        if (flag1 == CommandFlag::RAX ||
            flag1 == CommandFlag::RBX ||
            flag1 == CommandFlag::RCX ||
            flag1 == CommandFlag::RDX)
            push_register_to_temp(function, flag0, flag1);
        else if (flag1 == CommandFlag::None)
            push_value_to_temp(function, flag0, argument);

        function.backward();
    }

    void
    BasicState::execute_remove()
    {
        Function &function = get_current_function();

        function.get_temp().pop();

        function.backward();
    }

    void
    BasicState::execute_store(
        CommandFlag::EnumType flag1,
        const Value &argument)
    {
        Function &function = get_current_function();

        function.backward();
    }

    void
    BasicState::execute_move(
        CommandFlag::EnumType flag0,
        CommandFlag::EnumType flag1,
        const Value &argument,
        Value &rax)
    {
        Function &function = get_current_function();

        if (flag1 == CommandFlag::RAX ||
            flag1 == CommandFlag::RBX ||
            flag1 == CommandFlag::RCX ||
            flag1 == CommandFlag::RDX)
            move_to_register(flag1, argument);

        function.backward();
    }

    void
    BasicState::execute_native_call(
        const Value &argument)
    {
        Function &function = get_current_function();

        try
        {
            call_callback(argument, m_call_arguments);
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("voidBasicState::execute_native_call(const Value &argument)"));
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("void BasicState::execute_native_call(const Value &argument)"));
        }
        catch (const std::exception &exception)
        {
            throw ntl::Exception(
                exception,
                NTL_STRING("void BasicState::execute_native_call(const Value &argument)"));
        }

        function.backward();
    }

    void
    BasicState::execute_make_temp(
        const Value &argument)
    {
        Function &function = get_current_function();

        function.get_temp().push(Memory().reallocate(argument));

        function.backward();
    }

    void
    BasicState::execute_call(
        const Value &argument)
    {
        Function &function = get_current_function();

        call_function(argument, m_call_arguments);

        function.backward();
    }

    void
    BasicState::execute_call_push()
    {
        Function &function = get_current_function();

        try
        {
            m_call_arguments.push(function.get_temp().pop());
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("void BasicState::execute_call_push()"));
        }

        function.backward();
    }

} // namespace bvm

#endif
