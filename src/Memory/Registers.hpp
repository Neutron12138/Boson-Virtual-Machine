#ifndef __BOSONVM_MEMORY_REGISTER_HPP__
#define __BOSONVM_MEMORY_REGISTER_HPP__

#include <ntl/NTL.hpp>

namespace bvm
{
    /// @brief 寄存器
    class Registers : public ntl::Object
    {
    public:
        using SelfType = Registers;
        using ParentType = ntl::Object;

        /// @brief 寄存器
        struct NTL_ALIGN Register : public ntl::BasicObject
        {
        public:
            using SelfType = Register;
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
            Register() = default;
            explicit Register(const SelfType &from) = default;
            ~Register() = default;

        public:
            SelfType &operator=(const SelfType &from) = default;
        };

    public:
        Register rax;
        Register rbx;
        Register rcx;
        Register rdx;

    public:
        Registers() = default;
        explicit Registers(const SelfType &from) = default;
        ~Registers() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

} // namespace bvm

namespace ntl
{
    ntl::Serialization serialize(const bvm::Registers &object);

} // namespace ntl

#endif
