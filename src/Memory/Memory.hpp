#ifndef __BOSONVM_MEMORY_MEMORY_HPP__
#define __BOSONVM_MEMORY_MEMORY_HPP__

#include <vector>
#include <ntl/NTL.hpp>
#include "../Misc/IndexedManager.hpp"
#include "../Misc/AccessableStack.hpp"

namespace bvm
{
    /// @brief 内存
    class Memory : public ntl::Object
    {
    public:
        /// @brief 内存持有者
        using MemoryHolder = std::vector<ntl::Byte>;

        using SelfType = Memory;
        using ParentType = ntl::Object;

    public:
        /// @brief 内存持有者
        MemoryHolder m_holder;

    public:
        Memory() = default;
        explicit Memory(ntl::SizeT size);
        explicit Memory(const MemoryHolder &holder);
        explicit Memory(const SelfType &from) = default;
        ~Memory() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

    public:
        ntl::SizeT get_size() const;
        const MemoryHolder &get_holder() const;

        ntl::Byte *get_data();
        const ntl::Byte *get_data() const;

        template <typename ReturnType>
        ReturnType &get(ntl::SizeT offset = 0);
        template <typename ReturnType>
        const ReturnType &get(ntl::SizeT offset = 0) const;

        SelfType &set_holder(const MemoryHolder &holder);

    public:
        /// @brief 重新分配内存，会清空原有的值
        /// @param size 内存大小
        /// @return 本对象
        SelfType &reallocate(ntl::SizeT size);

        /// @brief 释放持有的内存
        /// @return 本对象
        SelfType &free();

        /// @brief 把内存中每一位设置为0
        /// @return 本对象
        SelfType &clear();

        /// @brief 对每stride个byte执行相同函数
        /// @tparam FuncType 函数类型
        /// @param func 函数
        /// @param stride 跨度
        /// @return 本对象
        template <typename FuncType, typename... ArgsType>
        SelfType &for_each(FuncType func, ntl::SizeT stride = 1, ArgsType &&...args);
    };

    /// @brief 内存管理器
    using MemoryManager = IndexedManager<Memory>;

    /// @brief 内存栈
    using MemoryStack = AccessableStack<Memory>;

    /// @brief 堆
    using Heap = MemoryManager;

    /// @brief 缓存栈
    using TempStack = MemoryStack;

    /// @brief 函数参数
    using FunctionArguments = MemoryStack;

} // namespace bvm

#endif
