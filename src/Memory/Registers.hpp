#ifndef __BOSONVM_MEMORY_REGISTER_HPP__
#define __BOSONVM_MEMORY_REGISTER_HPP__

#include <ntl/NTL.hpp>
#include "Value.hpp"
#include "../Misc/Resource.hpp"

namespace bvm
{
    /// @brief 寄存器
    class Registers : public ntl::Object
    {
    public:
        using SelfType = Registers;
        using ParentType = ntl::Object;

    public:
        Value rax;
        Value rbx;
        Value rcx;
        Value rdx;

    public:
        Registers() = default;
        explicit Registers(const SelfType &from) = default;
        ~Registers() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
    };

    using RegistersResource = Resource<Registers>;

} // namespace bvm

namespace ntl
{
    ntl::Serialization serialize(const bvm::Registers &registers);

} // namespace ntl

#endif
