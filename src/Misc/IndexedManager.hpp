#ifndef __BOSONVM_MISC_ITEMMANAGER_HPP__
#define __BOSONVM_MISC_ITEMMANAGER_HPP__

#include <map>
#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 项目管理器
    template <typename m_ItemType>
    class IndexedManager : public ntl::Object
    {
    public:
        /// @brief 项目类型
        using ItemType = m_ItemType;

        /// @brief 项目储存区
        using ItemStorage = std::map<ntl::SizeT, ItemType>;

        using SelfType = IndexedManager<ItemType>;
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
        const ItemStorage &get_storage() const;

    public:
        SelfType &add_item(ntl::SizeT index, const ItemType &item);

        ItemType &get_item(ntl::SizeT index);
        const ItemType &get_item(ntl::SizeT index) const;

        bool is_index_existed(ntl::SizeT index) const;
    };

} // namespace bvm

#endif
