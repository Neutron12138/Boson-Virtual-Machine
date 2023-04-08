#ifndef __BOSONVM_STATE_STATEDEBUGGER_HPP__
#define __BOSONVM_STATE_STATEDEBUGGER_HPP__

#include <ntl/NTL.hpp>
#include "BasicState.hpp"

namespace bvm
{
    /// @brief 状态调试器
    /// @tparam m_StateType 状态类型
    template <typename m_StateType>
    class StateDebugger : public m_StateType
    {
    public:
        using StateType = m_StateType;

        using SelfType = StateDebugger<StateType>;
        using ParentType = StateType;

    public:
        explicit StateDebugger(const StateType &state);
        explicit StateDebugger(const SelfType &from) = default;
        ~StateDebugger() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        virtual SelfType &print_current_instruction();
        virtual const SelfType &print_current_instruction() const;

    public:
        static ntl::String get_input();
    };

} // namespace bvm

#endif
