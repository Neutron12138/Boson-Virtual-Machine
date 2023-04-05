#ifndef __BOSONVM_INSTRUCTION_BASICFUNCTION_HPP__
#define __BOSONVM_INSTRUCTION_BASICFUNCTION_HPP__

#include <ntl/NTL.hpp>
#include "Instruction.hpp"
#include "../Memory/Memory.hpp"
#include "../Misc/AccessableStack.hpp"

namespace bvm
{
    /// @brief 基础函数
    class BasicFunction : public ntl::Object
    {
    public:
        using SelfType = BasicFunction;
        using ParentType = ntl::Object;

    protected:
        /// @brief 参数
        FunctionArguments m_arguments;

    public:
        BasicFunction() = default;
        explicit BasicFunction(const FunctionArguments &arguments);
        explicit BasicFunction(const SelfType &from) = default;
        ~BasicFunction() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        const FunctionArguments &get_arguments() const;
    };

} // namespace bvm

#endif
