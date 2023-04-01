#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

int main()
{
    bvm::Executer::InstructionManager manager;
    manager
        .add_instructions(0, bvm::Executer::InstructionContainer{
                                 bvm::Executer::Instruction(),
                                 bvm::Executer::Instruction(),
                                 bvm::Executer::Instruction(),
                             });

    std::cout << ntl::serialize(manager.get_instructions(0).at(0)) << std::endl;

    return 0;
}