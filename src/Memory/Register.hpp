#ifndef __BOSONVM_MEMORY_REGISTER_HPP__
#define __BOSONVM_MEMORY_REGISTER_HPP__

#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 寄存器
    class Register : public ntl::Object
    {
    public:
        using SelfType = Register;
        using ParentType = ntl::Object;

    public:
        ntl::Int64 rax;
        ntl::Int64 rbx;
        ntl::Int64 rcx;
        ntl::Int64 rdx;

    public:
        Register() = default;
        explicit Register(const SelfType &from) = default;
        ~Register() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace bvm

namespace ntl
{
    ntl::Serialization serialize(const bvm::Register &object);

} // namespace ntl

#endif
