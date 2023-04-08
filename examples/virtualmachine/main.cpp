#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

void my_func(bvm::BasicState &state, const bvm::FunctionArguments &arguments = bvm::FunctionArguments());

int main()
{
    try
    {
        bvm::VirtualMachine vm;
        vm.create_state<bvm::BasicState>(0);

        bvm::BasicState &state = *vm.get_state(0);
        state.add_callback(0, my_func);
        state.add_function(
            0,
            bvm::InstructionContainer{
                bvm::Instruction(bvm::Command::Load,
                                 bvm::CommandFlag::QWord,
                                 bvm::Value(666)),
                bvm::Instruction(bvm::Command::CallPush),
                bvm::Instruction(bvm::Command::NativeCall,
                                 bvm::Value(0)),
            });

        state.call_function(0).run().execute().execute();
    }
    catch (const ntl::CaughtException &exception)
    {
        std::cout << exception << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }

    return 0;
}

void my_func(bvm::BasicState &state, const bvm::FunctionArguments &arguments)
{
    std::cout << "Hello World!" << std::endl
              << "argument:" << arguments[0].get<ntl::Int64>() << std::endl;
}
