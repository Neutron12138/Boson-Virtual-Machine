#ifndef __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_CPP__
#define __BOSONVM_EXECUTER_INSTRUCTIONMANAGER_CPP__

#include "IndexedManager.hpp"

namespace bvm
{
    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::IndexedManager(
        const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemStorage &storage)
        : m_storage(storage) {}

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::operator[](
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
                NTL_STRING("template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType> typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::operator[](ntl::SizeT index)"));
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::operator[](
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
                NTL_STRING("template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType> const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::operator[](ntl::SizeT index) const"));
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::SelfType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::set_storage(
        const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemStorage &storage)
    {
        m_storage = storage;
        return *this;
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemStorage &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::get_storage() const
    {
        return m_storage;
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    bool
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::is_index_existed(
        ntl::SizeT index) const
    {
        return m_storage.find(index) != m_storage.cend();
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::SelfType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::add_item(
        ntl::SizeT index,
        const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &item)
    {
        m_storage.insert(
            std::pair<ntl::SizeT, ItemType>(
                index,
                item));
        return *this;
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::get_item(
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
                NTL_STRING("template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType> typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::get_item(ntl::SizeT index)"));
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::get_item(
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
                NTL_STRING("template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType> const typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::ItemType &IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::get_item(ntl::SizeT index) const"));
    }

    template <typename m_ItemType, typename m_ComparerType, typename m_AllocatorType>
    typename IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::SelfType &
    IndexedManager<m_ItemType, m_ComparerType, m_AllocatorType>::clear()
    {
        m_storage.clear();
        return *this;
    }

} // namespace bvm

#endif
