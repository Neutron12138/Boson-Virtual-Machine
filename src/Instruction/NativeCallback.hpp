#ifndef __BOSONVM_INSTRUCTION_NATIVECALLBACK_HPP__
#define __BOSONVM_INSTRUCTION_NATIVECALLBACK_HPP__

#include <ntl/NTL.hpp>
#include "../Memory/Memory.hpp"
#include "../Misc/IndexedManager.hpp"

namespace bvm
{
    class BasicState;

    /// @brief 本地回调
    class NativeCallback : public ntl::Object
    {
    public:
        using SelfType = NativeCallback;
        using ParentType = ntl::Object;

    public:
        NativeCallback() = default;
        explicit NativeCallback(const SelfType &from) = default;
        ~NativeCallback() override = default;

    public:
        SelfType &operator=(const SelfType &from) = default;
        virtual void operator()(BasicState &state,
                                const FunctionArguments &arguments);
    };

    /// @brief 本地回调管理器
    using NativeCallbackManager = IndexedManager<NativeCallback>;

} // namespace bvm

#endif
