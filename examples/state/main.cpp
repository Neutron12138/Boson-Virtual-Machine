#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

void my_func(bvm::BasicState &state, bvm::FunctionArguments arguments);

int main()
{
    try
    {
        bvm::BasicState state;

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

        bvm::StateDebugger<bvm::BasicState> debugger(state);
        debugger.call_function(0).run();
        debugger.print_current_instruction().execute();
        debugger.print_current_instruction().execute();
        debugger.print_current_instruction().execute();
    }
    catch (const ntl::CaughtException &exception)
    {
        std::cout << exception << std::endl;
    }
    catch (const ntl::Exception &exception)
    {
        std::cout << exception << std::endl;
    }
    catch (const std::exception &exception)
    {
        std::cout << exception.what() << std::endl;
    }

    return 0;
}

void my_func(bvm::BasicState &state, bvm::FunctionArguments arguments)
{
    std::cout << "Hello World!" << std::endl
              << "argument:" << arguments[0].get<ntl::Int64>() << std::endl;
}
