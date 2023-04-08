#ifndef __BOSONVM_EXECUTER_VIRTUALMACHINE_CPP__
#define __BOSONVM_EXECUTER_VIRTUALMACHINE_CPP__

#include "VirtualMachine.hpp"

namespace bvm
{
    StateManager &
    VirtualMachine::get_manager()
    {
        return m_state_manager;
    }

    const StateManager &
    VirtualMachine::get_manager() const
    {
        return m_state_manager;
    }

    StatePointer &
    VirtualMachine::get_state(
        ntl::SizeT index)
    {
        try
        {
            StatePointer &result = m_state_manager.get_item(index);
            return result;
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("StatePointer &VirtualMachine::get_state(ntl::SizeT index)"));
        }
    }

    const StatePointer &
    VirtualMachine::get_state(
        ntl::SizeT index) const
    {
        try
        {
            const StatePointer &result = m_state_manager.get_item(index);
            return result;
        }
        catch (const ntl::OutOfRangeException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("const StatePointer &VirtualMachine::get_state(ntl::SizeT index) const"));
        }
    }

    typename VirtualMachine::SelfType &
    VirtualMachine::add_state(
        ntl::SizeT index,
        const StatePointer &state)
    {
        m_state_manager.add_item(index, state);
        return *this;
    }

    template <typename StateType, typename... ArgsType>
    typename VirtualMachine::SelfType &
    VirtualMachine::create_state(
        ntl::SizeT index,
        ArgsType &&...args)
    {
        return add_state(
            index,
            ntl::make_shared<StateType>(
                std::forward<ArgsType>(args)...));
    }

    typename VirtualMachine::SelfType &
    VirtualMachine::execute_all()
    {
        StateManager::ItemStorage &storage = m_state_manager.get_storage();

        for (auto iter = storage.begin(); iter != storage.end(); iter++)
            execute(iter->second);

        return *this;
    }

    typename VirtualMachine::SelfType &
    VirtualMachine::execute(StatePointer &state)
    {
        try
        {
            state->execute();
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename VirtualMachine::SelfType &VirtualMachine::execute(StatePointer &state)"));
        }
        catch (const ntl::Exception &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("typename VirtualMachine::SelfType &VirtualMachine::execute(StatePointer &state)"));
        }

        return *this;
    }

} // namespace bvm

#endif
