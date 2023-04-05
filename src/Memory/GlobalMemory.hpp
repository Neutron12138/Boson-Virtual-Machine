#ifndef __BOSONVM_MEMORY_GLOBALMEMORY_HPP__
#define __BOSONVM_MEMORY_GLOBALMEMORY_HPP__

#include <ntl/NTL.hpp>
#include "Memory.hpp"
#include "Register.hpp"

namespace bvm
{
    /// @brief 全局存储区
    class GlobalMemory : public ntl::Object
    {
    public:
        using SelfType = GlobalMemory;
        using ParentType = ntl::Object;

    public:
        /// @brief 静态变量
        MemoryManager static_variables;

        /// @brief 全局变量
        MemoryManager global_variables;

        /// @brief 堆
        Heap heap;

        /// @brief 全局栈
        MemoryStack global_stack;

        /// @brief 寄存器
        Register registers;

    public:
        GlobalMemory() = default;
        explicit GlobalMemory(const SelfType &from) = default;
        ~GlobalMemory() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace bvm

#endif
