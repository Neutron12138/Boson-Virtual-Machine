#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

int main()
{
    bvm::Executer::InstructionManager manager;
    manager
        .add_item(0, bvm::Executer::InstructionContainer{
                         bvm::Executer::Instruction(),
                         bvm::Executer::Instruction(),
                         bvm::Executer::Instruction(),
                     });

    std::cout << ntl::serialize(manager[0].at(0)) << std::endl;

    return 0;
}