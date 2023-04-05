#ifndef __BOSONVM_MISC_ACCESSABLESTACK_HPP__
#define __BOSONVM_MISC_ACCESSABLESTACK_HPP__

#include <vector>
#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 可访问的栈
    /// @tparam m_ItemType 项目类型
    /// @tparam m_AllocatorType 分配器类型
    template <typename m_ItemType,
              typename m_AllocatorType = std::allocator<m_ItemType>>
    class AccessableStack : public ntl::Object
    {
    public:
        using ItemType = m_ItemType;
        using AllocatorType = m_AllocatorType;
        using ItemContainer = std::vector<ItemType, AllocatorType>;

        using SelfType = AccessableStack<ItemType, AllocatorType>;
        using ParentType = ntl::Object;

    protected:
        /// @brief 项目容器
        ItemContainer m_container;

    public:
        AccessableStack() = default;
        explicit AccessableStack(const ItemContainer &container);
        explicit AccessableStack(const SelfType &from) = default;
        ~AccessableStack() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        ItemType &operator[](ntl::SizeT index);
        const ItemType &operator[](ntl::SizeT index) const;

    public:
        SelfType &set_container(const ItemContainer &container);
        const ItemContainer &get_container() const;

        ntl::SizeT size() const;
        bool is_empty() const;

        ItemType &get_item(ntl::SizeT index);
        const ItemType &get_item(ntl::SizeT index) const;

    public:
        SelfType &push(const ItemType &item);
        ItemType pop();

        ItemType &top();
        const ItemType &top() const;

        SelfType &clear();
    };

} // namespace bvm

#endif
