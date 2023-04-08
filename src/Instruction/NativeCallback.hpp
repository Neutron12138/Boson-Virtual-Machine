#ifndef __BOSONVM_INSTRUCTION_NATIVECALLBACK_HPP__
#define __BOSONVM_INSTRUCTION_NATIVECALLBACK_HPP__

#include <functional>
#include <ntl/NTL.hpp>
#include "../Memory/Memory.hpp"
#include "../Misc/IndexedManager.hpp"

namespace bvm
{
    class BasicState;

    /*
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
                                    const FunctionArguments &arguments = FunctionArguments());
        };

        /// @brief 本地回调指针
        using NativeCallbackPointer = ntl::SharedPointer<NativeCallback>;

        /// @brief 本地回调管理器
        using NativeCallbackManager = IndexedManager<NativeCallbackPointer>;
        */

    /// @brief 本地回调函数类型
    using NativeCallbackType = void(BasicState &, FunctionArguments);

    /// @brief 本地回调
    using NativeCallback = std::function<NativeCallbackType>;

    /// @brief 本地回调管理器
    using NativeCallbackManager = IndexedManager<NativeCallback>;

} // namespace bvm

#endif
