#ifndef __BOSONVM_MISC_ITEMMANAGER_HPP__
#define __BOSONVM_MISC_ITEMMANAGER_HPP__

#include <map>
#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 项目管理器
    template <typename m_ItemType,
              typename m_ComparerType = std::less<ntl::SizeT>,
              typename m_AllocatorType = std::allocator<std::pair<const ntl::SizeT, m_ItemType>>>
    class IndexedManager : public ntl::Object
    {
    public:
        /// @brief 项目类型
        using ItemType = m_ItemType;

        /// @brief 比较器类型
        using ComparerType = m_ComparerType;

        /// @brief 分配器类型
        using AllocatorType = m_AllocatorType;

        /// @brief 项目储存区
        using ItemStorage =
            std::map<ntl::SizeT, ItemType, ComparerType, AllocatorType>;

        using SelfType = IndexedManager<ItemType, ComparerType, AllocatorType>;
        using ParentType = ntl::Object;

    protected:
        /// @brief 项目储存区
        ItemStorage m_storage;

    public:
        IndexedManager() = default;
        explicit IndexedManager(const ItemStorage &storage);
        explicit IndexedManager(const SelfType &from) = default;
        ~IndexedManager() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        ItemType &operator[](ntl::SizeT index);
        const ItemType &operator[](ntl::SizeT index) const;

    public:
        SelfType &set_storage(const ItemStorage &storage);

        ItemStorage &get_storage();
        const ItemStorage &get_storage() const;

        bool is_index_existed(ntl::SizeT index) const;

    public:
        SelfType &add_item(ntl::SizeT index, const ItemType &item);

        ItemType &get_item(ntl::SizeT index);
        const ItemType &get_item(ntl::SizeT index) const;

        SelfType &clear();
    };

} // namespace bvm

#endif
