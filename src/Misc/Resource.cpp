#ifndef __BOSONVM_MISC_RESOURCE_CPP__
#define __BOSONVM_MISC_RESOURCE_CPP__

#include "Resource.hpp"

namespace bvm
{
    template <typename m_ResourceType, typename m_PointerType>
    Resource<m_ResourceType, m_PointerType>::Resource(
        const ResourceType &from)
        : m_pointer(
              new Resource<m_ResourceType, m_PointerType>::ResourceType(
                  from)) {}

    template <typename m_ResourceType, typename m_PointerType>
    typename Resource<m_ResourceType, m_PointerType>::ResourceType &
    Resource<m_ResourceType, m_PointerType>::operator*() const
    {
        try
        {
            return *m_pointer;
        }
        catch (const ntl::NullPointerException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("template <typename m_ResourceType, typename m_PointerType> typename Resource<m_ResourceType, m_PointerType>::ResourceType &Resource<m_ResourceType, m_PointerType>::operator*() const"));
        }
    }

    template <typename m_ResourceType, typename m_PointerType>
    typename Resource<m_ResourceType, m_PointerType>::ResourceType &
    Resource<m_ResourceType, m_PointerType>::operator->() const
    {
        try
        {
            return *m_pointer;
        }
        catch (const ntl::NullPointerException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("template <typename m_ResourceType, typename m_PointerType> typename Resource<m_ResourceType, m_PointerType>::ResourceType &Resource<m_ResourceType, m_PointerType>::operator->() const"));
        }
    }

    template <typename m_ResourceType, typename m_PointerType>
    typename Resource<m_ResourceType, m_PointerType>::PointerType &
    Resource<m_ResourceType, m_PointerType>::get_pointer()
    {
        return m_pointer;
    }

    template <typename m_ResourceType, typename m_PointerType>
    const typename Resource<m_ResourceType, m_PointerType>::PointerType &
    Resource<m_ResourceType, m_PointerType>::get_pointer() const
    {
        return m_pointer;
    }

    template <typename m_ResourceType, typename m_PointerType>
    bool
    Resource<m_ResourceType, m_PointerType>::is_nullptr() const
    {
        return m_pointer.is_nullptr();
    }

    template <typename m_ResourceType, typename m_PointerType>
    typename Resource<m_ResourceType, m_PointerType>::SelfType &
    Resource<m_ResourceType, m_PointerType>::reset(
        const typename Resource<m_ResourceType, m_PointerType>::ResourceType &from)
    {
        m_pointer =
            ntl::make_shared<ResourceType>(from);
        return *this;
    }

    template <typename m_ResourceType, typename m_PointerType>
    typename Resource<m_ResourceType, m_PointerType>::SelfType
    Resource<m_ResourceType, m_PointerType>::copy() const
    {
        try
        {
            return SelfType(*this);
        }
        catch (const ntl::NullPointerException &exception)
        {
            throw ntl::CaughtException(
                exception,
                NTL_STRING("template <typename m_ResourceType, typename m_PointerType> typename Resource<m_ResourceType, m_PointerType>::SelfTypeResource<m_ResourceType, m_PointerType>::copy() const"));
        }
    }

    template <typename m_ResourceType, typename m_PointerType>
    typename Resource<m_ResourceType, m_PointerType>::SelfType &
    Resource<m_ResourceType, m_PointerType>::swap(
        typename Resource<m_ResourceType, m_PointerType>::SelfType &another)
    {
        m_pointer.swap(another.m_pointer);
        return *this;
    }

} // namespace bvm

#endif
