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
        SelfType &add_callback(ntl::SizeT index,
                               NativeCallback callback);

        /// @brief 调用一个函数
        /// @param index 索引
        /// @param arguments 参数
        /// @return 本对象
        SelfType &call_function(ntl::SizeT index,
                                const FunctionArguments &arguments = FunctionArguments());

        /// @brief 调用一个本地回调
        /// @param index 索引
        /// @param arguments 参数
        /// @return 本对象
        SelfType &call_callback(ntl::SizeT index,
                                const FunctionArguments &arguments = FunctionArguments());

        /// @brief 中止当前函数
        /// @param result 返回值（如果当前函数需要，留空则不会返回）
        /// @return 本对象
        virtual SelfType &abort_current_function(std::optional<Memory> result);

        /// @brief 中止本状态
        /// @return 本对象
        virtual SelfType &abort_self();

    public:
        /// @brief 执行一条指令
        /// @return 本对象
        virtual SelfType &execute();

        /// @brief 执行一条指令
        /// @return 本对象
        virtual SelfType &execute(const Instruction &instruction);

        /// @brief 运行本状态
        /// @return 本对象
        virtual SelfType &run();

        /// @brief 停止本状态
        /// @return 本对象
        virtual SelfType &stop();

    public:
        Function &get_current_function();
        const Function &get_current_function() const;

        const Instruction &get_current_instruction() const;

    public:
        virtual void push_register_to_temp(Function &function,
                                           CommandFlag::EnumType flag0,
                                           CommandFlag::EnumType flag1);

        virtual void push_value_to_temp(Function &function,
                                        CommandFlag::EnumType flag0,
                                        const Value &argument);

        virtual void move_to_register(CommandFlag::EnumType flag1,
                                      const Value &argument);

    public:
        virtual void execute_none();
        virtual void execute_load(CommandFlag::EnumType flag0,
                                  CommandFlag::EnumType flag1,
                                  const Value &argument);
        virtual void execute_remove();
        virtual void execute_store(CommandFlag::EnumType flag1,
                                   const Value &argument);
        virtual void execute_move(CommandFlag::EnumType flag0,
                                  CommandFlag::EnumType flag1,
                                  const Value &argument,
                                  Value &rax);
        virtual void execute_native_call(const Value &argument);
        virtual void execute_make_temp(const Value &argument);
        virtual void execute_call(const Value &argument);
        virtual void execute_call_push();
    };

    /// @brief 状态指针
    using StatePointer = ntl::SharedPointer<BasicState>;

    /// @brief 状态管理器
    using StateManager = IndexedManager<StatePointer>;

} // namespace bvm

#endif
