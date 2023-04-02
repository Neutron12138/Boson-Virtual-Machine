#ifndef __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_CPP__
#define __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_CPP__

#include "IndexedManager.hpp"

namespace bvm
{
    template <typename m_ItemType>
    IndexedManager<m_ItemType>::IndexedManager(
        const typename IndexedManager<m_ItemType>::ItemStorage &storage)
        : m_storage(storage) {}

    template <typename m_ItemType>
    typename IndexedManager<m_ItemType>::ItemType &
    IndexedManager<m_ItemType>::operator[](
        ntl::SizeT index)
    {
        if (is_index_existed(index))
            return m_storage.at(index);
        else
            throw ntl::OutOfRangeException(
                ntl::StringUtils::to_string(
                    NTL_STRING("Index: "),
                    index,
                    NTL_STRING(" is not in storage")),
                NTL_STRING("template <typename m_ItemType> typename IndexedManager<m_ItemType>::ItemType &IndexedManager<m_ItemType>::operator[](ntl::SizeT index)"));
    }

    template <typename m_ItemType>
    const typename IndexedManager<m_ItemType>::ItemType &
    IndexedManager<m_ItemType>::operator[](
        ntl::SizeT index) const
    {
        if (is_index_existed(index))
            return m_storage.at(index);
        else
            throw ntl::OutOfRangeException(
                ntl::StringUtils::to_string(
                    NTL_STRING("Index: "),
                    index,
                    NTL_STRING(" is not in storage")),
                NTL_STRING("template <typename m_ItemType> const typename IndexedManager<m_ItemType>::ItemType &IndexedManager<m_ItemType>::operator[](ntl::SizeT index) const"));
    }

    template <typename m_ItemType>
    typename IndexedManager<m_ItemType>::SelfType &
    IndexedManager<m_ItemType>::set_storage(
        const typename IndexedManager<m_ItemType>::ItemStorage &storage)
    {
        m_storage = storage;
        return *this;
    }

    template <typename m_ItemType>
    const typename IndexedManager<m_ItemType>::ItemStorage &
    IndexedManager<m_ItemType>::get_storage() const
    {
        return m_storage;
    }

    template <typename m_ItemType>
    typename IndexedManager<m_ItemType>::SelfType &
    IndexedManager<m_ItemType>::add_item(
        ntl::SizeT index,
        const typename IndexedManager<m_ItemType>::ItemType &item)
    {
        m_storage.insert(
            std::pair<ntl::SizeT, ItemType>(
                index,
                item));
        return *this;
    }

    template <typename m_ItemType>
    typename IndexedManager<m_ItemType>::ItemType &
    IndexedManager<m_ItemType>::get_item(
        ntl::SizeT index)
    {
        if (is_index_existed(index))
            return m_storage.at(index);
        else
            throw ntl::OutOfRangeException(
                ntl::StringUtils::to_string(
                    NTL_STRING("Index: "),
                    index,
                    NTL_STRING(" is not in storage")),
                NTL_STRING("template <typename m_ItemType> typename IndexedManager<m_ItemType>::ItemType &IndexedManager<m_ItemType>::get_item(ntl::SizeT index)"));
    }

    template <typename m_ItemType>
    const typename IndexedManager<m_ItemType>::ItemType &
    IndexedManager<m_ItemType>::get_item(
        ntl::SizeT index) const
    {
        if (is_index_existed(index))
            return m_storage.at(index);
        else
            throw ntl::OutOfRangeException(
                ntl::StringUtils::to_string(
                    NTL_STRING("Index: "),
                    index,
                    NTL_STRING(" is not in storage")),
                NTL_STRING("template <typename m_ItemType> const typename IndexedManager<m_ItemType>::ItemType &IndexedManager<m_ItemType>::get_item(ntl::SizeT index) const"));
    }

    template <typename m_ItemType>
    bool
    IndexedManager<m_ItemType>::is_index_existed(
        ntl::SizeT index) const
    {
        return m_storage.find(index) != m_storage.cend();
    }

} // namespace bvm

#endif
