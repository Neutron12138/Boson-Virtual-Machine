#ifndef __BOSONVM_INSTRUCTION_DEFAULTNATIVECALLBACKS_CPP__
#define __BOSONVM_INSTRUCTION_DEFAULTNATIVECALLBACKS_CPP__

#include "DefaultNativeCallbacks.hpp"

namespace bvm
{
    namespace DefaultNativeCallbacks
    {
        void
        print(
            BasicState &state,
            FunctionArguments arguments)
        {
            PrintEnum target = arguments.pop().get<PrintEnum>();
            PrintEnum method = arguments.pop().get<PrintEnum>();

            ntl::OutputStream *stream = nullptr;

            switch (target)
            {
            case PrintEnum::StdOut:
                stream = &ntl::nout;
                break;

            default:
                break;
            }

            while (arguments.size() > 0)
            {
                Memory arg = arguments.pop();

                switch (method)
                {
                case PrintEnum::SingleChar:
                    stream->operator<<(
                        reinterpret_cast<ntl::Char>(
                            arg.get_data()));
                    break;

                case PrintEnum::WideChar:
                    stream->operator<<(
                        reinterpret_cast<ntl::CharW>(
                            arg.get_data()));
                    break;

                case PrintEnum::Number:
                {
                    ntl::SizeT size = arg.size();
                    
                    if (size >= 8)
                        stream->operator<<(
                            reinterpret_cast<ntl::Int64>(
                                arg.get_data()));
                    else if (size >= 4)
                        stream->operator<<(
                            reinterpret_cast<ntl::Int32>(
                                arg.get_data()));
                    else if (size >= 2)
                        stream->operator<<(
                            reinterpret_cast<ntl::Int16>(
                                arg.get_data()));
                    else if (size >= 1)
                        stream->operator<<(
                            static_cast<ntl::Int16>(
                                reinterpret_cast<ntl::Int8>(
                                    arg.get_data())));
                }

                break;

                default:
                    break;
                }
            }
        }

    } // namespace DefaultNativeCallbacks

} // namespace bvm

#endif
