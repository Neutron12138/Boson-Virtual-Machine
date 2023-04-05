#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

/*struct MyFunc : public bvm::NativeCallback
{
    void operator()(bvm::BasicState &state, const bvm::FunctionArguments &arguments = bvm::FunctionArguments()) override
    {
        std::cout << "Hello World!" << std::endl;
    }
};*/

void my_func(bvm::BasicState &state, const bvm::FunctionArguments &arguments = bvm::FunctionArguments());

int main()
{
    bvm::BasicState state;

    state.add_function(0, my_func);
    //state.execute_native_call(bvm::Instruction());

    return 0;
}

void my_func(bvm::BasicState &state, const bvm::FunctionArguments &arguments)
{
    std::cout << "Hello World!" << std::endl;
}
