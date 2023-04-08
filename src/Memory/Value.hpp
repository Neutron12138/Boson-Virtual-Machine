#ifndef __BOSONVM_MEMORY_VALUE_HPP__
#define __BOSONVM_MEMORY_VALUE_HPP__

#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 值
    struct NTL_ALIGN Value : public ntl::BasicObject
    {
    public:
        using SelfType = Value;
        using ParentType = ntl::BasicObject;

    public:
        union
        {
            ntl::Int8 byte;
            ntl::Int16 word;
            ntl::Int32 dword;
            ntl::Int64 qword;
        };

    public:
        Value() = default;
        Value(ntl::Int64 value);
        explicit Value(const SelfType &from) = default;
        ~Value() = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        SelfType &operator=(ntl::Int64 value);
        operator ntl::Int64() const;
    };

} // namespace bvm

#endif
