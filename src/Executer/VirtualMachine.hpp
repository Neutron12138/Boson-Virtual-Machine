#ifndef __BOSONVM_EXECUTER_VIRTUALMACHINE_HPP__
#define __BOSONVM_EXECUTER_VIRTUALMACHINE_HPP__

#include <ntl/NTL.hpp>
#include "../State/BasicState.hpp"

namespace bvm
{
    /// @brief 虚拟机
    class VirtualMachine : public ntl::Object
    {
    public:
        using SelfType = VirtualMachine;
        using ParentType = ntl::Object;

    protected:
        /// @brief 状态管理器
        StateManager m_state_manager;

    public:
        VirtualMachine() = default;
        explicit VirtualMachine(const SelfType &from) = default;
        ~VirtualMachine() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        StateManager &get_manager();
        const StateManager &get_manager() const;

        StatePointer &get_state(ntl::SizeT index);
        const StatePointer &get_state(ntl::SizeT index) const;

    public:
        SelfType &add_state(ntl::SizeT index, const StatePointer &state);
        template <typename StateType, typename... ArgsType>
        SelfType &create_state(ntl::SizeT index, ArgsType &&...args);

    public:
        /// @brief 执行所有的state
        /// @return 本对象
        SelfType &execute_all();

        /// @brief 执行单个state
        /// @param state 状态
        /// @return 本对象
        SelfType &execute(StatePointer &state);
    };

} // namespace bvm

#endif
