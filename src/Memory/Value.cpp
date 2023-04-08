#ifndef __BOSONVM_MEMORY_VALUE_CPP__
#define __BOSONVM_MEMORY_VALUE_CPP__

#include "Value.hpp"

namespace bvm
{
    Value::Value(
        ntl::Int64 value)
        : qword(value) {}

    typename Value::SelfType &
    Value::operator=(ntl::Int64 value)
    {
        qword = value;
        return *this;
    }

    Value::operator ntl::Int64() const
    {
        return qword;
    }

} // namespace bvm

#endif
