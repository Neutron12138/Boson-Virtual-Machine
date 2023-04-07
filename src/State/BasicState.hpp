#ifndef __BOSONVM_STATE_BASICSTATE_HPP__
#define __BOSONVM_STATE_BASICSTATE_HPP__

#include <optional>
#include <ntl/NTL.hpp>
#include "../Instruction/Instruction.hpp"
#include "../Instruction/Function.hpp"
#include "../Memory/GlobalMemory.hpp"
#include "../Instruction/NativeCallback.hpp"

namespace bvm
{
    /// @brief 基础状态，一个状态就是一个程序
    class BasicState : public ntl::Object
    {
    public:
        using SelfType = BasicState;
        using ParentType = ntl::Object;

        enum Status
        {
            /// @brief 停止的
            Stopped = 0,

            /// @brief 运行中
            Running,

            /// @brief 等待中
            Waiting,

            /// @brief 终止的
            Aborted,
        };

    protected:
        /// @brief 指令管理器
        InstructionManager m_instruction_manager;

        /// @brief 本地回调管理器
        NativeCallbackManager m_native_manager;

        /// @brief 调用栈
        FunctionCallStack m_call_stack;

        /// @brief 全局存储区
        GlobalMemory m_global_memory;

        /// @brief 调用参数
        FunctionArguments m_call_arguments;

        /// @brief 状态
        Status m_status = Status::Stopped;

    public:
        BasicState() = default;
        explicit BasicState(const InstructionManager &manager);
        explicit BasicState(const InstructionManager &manager,
                            const GlobalMemory &memory);
        explicit BasicState(const SelfType &from) = default;
        ~BasicState() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const InstructionManager &get_instruction_manager() const;
        const NativeCallbackManager &get_native_manager() const;
        const FunctionCallStack &get_call_stack() const;
        const GlobalMemory &get_global_memory() const;
        const FunctionArguments &get_call_arguments() const;
        Status get_status() const;

        bool is_call_stack_empty() const;

        FunctionArguments &get_global_stack();
        Registers &get_registers();

    public:
        /// @brief 添加一个函数
        /// @param index 索引
        /// @param instructions 函数的指令
        /// @return 本对象
        SelfType &add_function(ntl::SizeT index,
                               const InstructionContainer &instructions);

        /// @brief 添加一个本地回调
        /// @param index 索引
        /// @param callback 回调
        /// @return 本对象
        SelfType &add_function(ntl::SizeT index,
                               NativeCallback callback);

        /// @brief 调用一个函数
        /// @param index 函数索引
        /// @param arguments 参数
        /// @return 本对象
        SelfType &call_function(ntl::SizeT index,
                                const FunctionArguments arguments = FunctionArguments());

        /// @brief 中止当前函数
        /// @param result 返回值（如果当前函数需要，留空则不会返回）
        /// @return 本对象
        SelfType &abort_current_function(std::optional<ntl::Int64> result);

        /// @brief 中止本状态
        /// @return 本对象
        SelfType &abort_self();

    public:
        /// @brief 执行一条指令
        /// @return 本对象
        SelfType &execute();

        /// @brief 执行一条指令
        /// @return 本对象
        SelfType &execute(const Instruction &instruction);

        /// @brief 运行本状态
        /// @return 本对象
        SelfType &run();

        /// @brief 停止本状态
        /// @return 本对象
        SelfType &stop();

    protected:
        virtual void execute_none(const Instruction &instruction);
        virtual void execute_load(const Instruction &instruction);
        virtual void execute_remove(const Instruction &instruction);
        virtual void execute_store(const Instruction &instruction);
        virtual void execute_move(const Instruction &instruction);
        virtual void execute_native_call(const Instruction &instruction);
    };

} // namespace bvm

#endif
