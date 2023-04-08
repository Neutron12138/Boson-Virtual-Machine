#ifndef __BOSONVM_STATE_STATEDEBUGGER_CPP__
#define __BOSONVM_STATE_STATEDEBUGGER_CPP__

#include "StateDebugger.hpp"

namespace bvm
{
    template <typename m_StateType>
    StateDebugger<m_StateType>::StateDebugger(
        const typename StateDebugger<m_StateType>::StateType &state)
        : ParentType(state) {}

    template <typename m_StateType>
    typename StateDebugger<m_StateType>::SelfType &
    StateDebugger<m_StateType>::print_current_instruction()
    {
        try
        {
            ntl::nout << ntl::serialize(ParentType::get_current_instruction()) << std::endl;
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("template <typename m_StateType> typename StateDebugger<m_StateType>::SelfType &StateDebugger<m_StateType>::print_current_instruction()"));
        }

        return *this;
    }

    template <typename m_StateType>
    const typename StateDebugger<m_StateType>::SelfType &
    StateDebugger<m_StateType>::print_current_instruction() const
    {
        try
        {
            ntl::nout << ntl::serialize(ParentType::get_current_instruction()) << std::endl;
        }
        catch (const ntl::CaughtException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("template <typename m_StateType> const typename StateDebugger<m_StateType>::SelfType &StateDebugger<m_StateType>::print_current_instruction() const"));
        }

        return *this;
    }

    template <typename m_StateType>
    ntl::String
    StateDebugger<m_StateType>::get_input()
    {
        ntl::String result;
        ntl::nin >> result;
        return result;
    }

} // namespace bvm

#endif
