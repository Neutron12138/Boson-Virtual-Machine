#ifndef __BOSONVM_MISC_RESOURCE_HPP__
#define __BOSONVM_MISC_RESOURCE_HPP__

#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 资源
    template <
        typename m_ResourceType,
        typename m_PointerType = ntl::SharedPointer<m_ResourceType>>
    class Resource : public ntl::Copyable
    {
    public:
        using ResourceType = m_ResourceType;
        using PointerType = m_PointerType;

        using SelfType = Resource<ResourceType>;
        using ParentType = ntl::Copyable;

    protected:
        /// @brief 指向资源的指针
        PointerType m_pointer;

    public:
        Resource() = default;
        explicit Resource(const ResourceType &from);
        explicit Resource(const SelfType &from) = default;
        ~Resource() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;

        ResourceType &operator*() const;
        ResourceType &operator->() const;

    public:
        PointerType &get_pointer();
        const PointerType &get_pointer() const;

        bool is_nullptr() const;

        SelfType &reset(const ResourceType &from);

    public:
        SelfType copy() const override;
        SelfType &swap(SelfType &another) override;
    };

} // namespace bvm

#endif
