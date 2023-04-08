#ifndef __BOSONVM_MISC_ACCESSABLESTACK_CPP__
#define __BOSONVM_MISC_ACCESSABLESTACK_CPP__

#include "AccessableStack.hpp"

namespace bvm
{
    template <typename m_ItemType, typename m_AllocatorType>
    template <typename AnotherAllocatorType>
    AccessableStack<m_ItemType, m_AllocatorType>::AccessableStack(
        const std::vector<
            typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType,
            AnotherAllocatorType> &container)
        : m_container(container) {}

    template <typename m_ItemType, typename m_AllocatorType>
    template <typename AnotherAllocatorType>
    AccessableStack<m_ItemType, m_AllocatorType>::AccessableStack(
        const AccessableStack<
            typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType,
            AnotherAllocatorType> &from)
        : m_container(from.get_container()) {}

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &
    AccessableStack<m_ItemType, m_AllocatorType>::operator[](
        ntl::SizeT index)
    {
        try
        {
            ItemType &result = m_container.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::operator[](ntl::SizeT index)"));
        }
    }

    template <typename m_ItemType, typename m_AllocatorType>
    const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &
    AccessableStack<m_ItemType, m_AllocatorType>::operator[](
        ntl::SizeT index) const
    {
        try
        {
            const ItemType &result = m_container.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::operator[](ntl::SizeT index) const"));
        }
    }

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::SelfType &
    AccessableStack<m_ItemType, m_AllocatorType>::set_container(
        const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemContainer &container)
    {
        m_container = container;
        return *this;
    }

    template <typename m_ItemType, typename m_AllocatorType>
    const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemContainer &
    AccessableStack<m_ItemType, m_AllocatorType>::get_container() const
    {
        return m_container;
    }

    template <typename m_ItemType, typename m_AllocatorType>
    ntl::SizeT
    AccessableStack<m_ItemType, m_AllocatorType>::size() const
    {
        return m_container.size();
    }

    template <typename m_ItemType, typename m_AllocatorType>
    bool
    AccessableStack<m_ItemType, m_AllocatorType>::is_empty() const
    {
        return size() == 0;
    }

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &
    AccessableStack<m_ItemType, m_AllocatorType>::get_item(
        ntl::SizeT index)
    {
        try
        {
            ItemType &result = m_container.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::get_item(ntl::SizeT index)"));
        }
    }

    template <typename m_ItemType, typename m_AllocatorType>
    const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &
    AccessableStack<m_ItemType, m_AllocatorType>::get_item(
        ntl::SizeT index) const
    {
        try
        {
            const ItemType &result = m_container.at(index);
            return result;
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::get_item(ntl::SizeT index) const"));
        }
    }

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::SelfType &
    AccessableStack<m_ItemType, m_AllocatorType>::push(
        const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &item)
    {
        m_container.push_back(item);
        return *this;
    }

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType
    AccessableStack<m_ItemType, m_AllocatorType>::pop()
    {
        if (m_container.size() == 0)
            throw ntl::OutOfRangeException(
                NTL_STRING("The stack is empty"),
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::pop()"));

        ItemType result = ItemType(top());
        m_container.pop_back();
        return ItemType(result);
    }

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &
    AccessableStack<m_ItemType, m_AllocatorType>::top()
    {
        if (m_container.size() == 0)
            throw ntl::OutOfRangeException(
                NTL_STRING("The stack is empty"),
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::top()"));

        return m_container.at(size() - 1);
    }

    template <typename m_ItemType, typename m_AllocatorType>
    const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &
    AccessableStack<m_ItemType, m_AllocatorType>::top() const
    {
        if (m_container.size() == 0)
            throw ntl::OutOfRangeException(
                NTL_STRING("The stack is empty"),
                NTL_STRING("template <typename m_ItemType, typename m_AllocatorType> const typename AccessableStack<m_ItemType, m_AllocatorType>::ItemType &AccessableStack<m_ItemType, m_AllocatorType>::top() const"));

        return m_container.at(size() - 1);
    }

    template <typename m_ItemType, typename m_AllocatorType>
    typename AccessableStack<m_ItemType, m_AllocatorType>::SelfType &
    AccessableStack<m_ItemType, m_AllocatorType>::clear()
    {
        m_container.clear();
        return *this;
    }

} // namespace bvm

#endif
