#ifndef __BOSONVM_MEMORY_MEMORY_CPP__
#define __BOSONVM_MEMORY_MEMORY_CPP__

#include "Memory.hpp"

namespace bvm
{
    Memory::Memory(
        ntl::SizeT size)
        : m_holder(size) {}

    Memory::Memory(
        const MemoryHolder &holder)
        : m_holder(holder) {}

    ntl::SizeT
    Memory::get_size() const
    {
        return m_holder.size();
    }

    const typename Memory::MemoryHolder &
    Memory::get_holder() const
    {
        return m_holder;
    }

    ntl::Byte *
    Memory::get_data()
    {
        return m_holder.data();
    }

    const ntl::Byte *
    Memory::get_data() const
    {
        return m_holder.data();
    }

    template <typename ReturnType>
    ReturnType &
    Memory::get(
        ntl::SizeT offset)
    {
        return *reinterpret_cast<ReturnType *>(
            &m_holder.at(offset));
    }

    template <typename ReturnType>
    const ReturnType &
    Memory::get(
        ntl::SizeT offset) const
    {
        return *reinterpret_cast<ReturnType *>(
            &m_holder.at(offset));
    }

    typename Memory::SelfType &
    Memory::set_holder(
        const MemoryHolder &holder)
    {
        m_holder = holder;
        return *this;
    }

    typename Memory::SelfType &
    Memory::reallocate(
        ntl::SizeT size)
    {
        m_holder.resize(size);
        return *this;
    }

    typename Memory::SelfType &
    Memory::free()
    {
        m_holder.clear();
        return *this;
    }

    typename Memory::SelfType &
    Memory::clear()
    {
        for_each([](ntl::SizeT index, ntl::Byte *element) -> void
                 { *element = 0; });
        return *this;
    }

    template <typename FuncType, typename... ArgsType>
    typename Memory::SelfType &
    Memory::for_each(
        FuncType func,
        ntl::SizeT stride,
        ArgsType &&...args)
    {
        for (ntl::SizeT i = 0; i < m_holder.size(); i += stride)
            func(
                i,
                &m_holder.at(i),
                std::forward<ArgsType>(args)...);
        return *this;
    }

} // namespace bvm

#endif
