#ifndef __BOSONVM_MEMORY_UNIFORM_CPP__
#define __BOSONVM_MEMORY_UNIFORM_CPP__

#include "Uniform.hpp"

namespace bvm
{
    Uniform::Uniform(
        Uniform::Purview purview)
        : m_purview(purview) {}

    Uniform::Uniform(
        Uniform::Purview purview,
        ntl::SizeT size)
        : m_purview(purview),
          m_holder(size) {}

    Uniform::Uniform(
        Uniform::Purview purview,
        const DataHolder &holder)
        : m_purview(purview),
          m_holder(holder) {}

    template <typename IteratorType>
    Uniform::Uniform(
        Uniform::Purview purview,
        const IteratorType &begin,
        const IteratorType &end)
        : m_purview(purview),
          m_holder(begin, end) {}

    typename Uniform::SelfType &
    Uniform::set_holder(
        const DataHolder &holder)
    {
        m_holder = holder;
        return *this;
    }

    typename Uniform::SelfType &
    Uniform::set_purview(
        Uniform::Purview purview)
    {
        m_purview = purview;
        return *this;
    }

    const typename Uniform::DataHolder &
    Uniform::get_holder() const
    {
        return m_holder;
    }

    Uniform::Purview
    Uniform::get_purview() const
    {
        return m_purview;
    }

    ntl::SizeT
    Uniform::size() const
    {
        return m_holder.size();
    }

    ntl::Byte *
    Uniform::get_data()
    {
        return m_holder.data();
    }

    const ntl::Byte *
    Uniform::get_data() const
    {
        return m_holder.data();
    }

    template <typename DataType>
    DataType *
    Uniform::as(
        ntl::SizeT offset)
    {
        try
        {
            return reinterpret_cast<DataType *>(
                &m_holder.at(offset));
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("template <typename DataType> DataType *Uniform::as(ntl::SizeT offset)"));
        }
    }

    template <typename DataType>
    const DataType *
    Uniform::as(
        ntl::SizeT offset) const
    {
        try
        {
            return reinterpret_cast<DataType *>(
                &m_holder.at(offset));
        }
        catch (const std::out_of_range &exception)
        {
            throw ntl::OutOfRangeException(
                exception,
                NTL_STRING("template <typename DataType> const DataType *Uniform::as(ntl::SizeT offset) const"));
        }
    }

} // namespace bvm

#endif
