#ifndef __BOSONVM_INSTRUCTION_FUNCTION_HPP__
#define __BOSONVM_INSTRUCTION_FUNCTION_HPP__

#include <ntl/NTL.hpp>
#include "BasicFunction.hpp"
#include "Instruction.hpp"
#include "../Memory/Memory.hpp"
#include "../Misc/AccessableStack.hpp"

namespace bvm
{
    /// @brief 函数
    class Function : public BasicFunction
    {
    public:
        using SelfType = Function;
        using ParentType = BasicFunction;

    protected:
        /// @brief 指令
        InstructionContainerResource m_instructions;

        /// @brief 变量
        MemoryManagerResource m_variables;

        /// @brief 缓存
        TempStackResource m_temp;

        /// @brief 执行位置
        ntl::SizeT m_position = 0;

    public:
        explicit Function(const InstructionContainerResource &instructions);
        explicit Function(const InstructionContainerResource &instructions,
                          const MemoryStackResource &arguments);
        explicit Function(const SelfType &from) = default;
        ~Function() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const InstructionContainerResource &get_instructions() const;
        const MemoryManagerResource &get_variables() const;
        const MemoryStackResource &get_temp() const;
        ntl::SizeT get_position() const;

        ntl::SizeT size() const;
        bool is_end() const;

        MemoryManagerResource &get_variables();
        MemoryStackResource &get_temp();

    public:
        const Instruction &get_instruction() const;
        SelfType &forward(ntl::SizeT offset = 1);
        SelfType &backward(ntl::SizeT offset = 1);
    };

    /// @brief 函数调用栈
    using FunctionCallStack = AccessableStack<Function>;

} // namespace bvm

#endif
