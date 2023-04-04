#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

int main()
{
    bvm::InstructionManager manager;
    manager
        .add_item(0, bvm::InstructionContainer{
                         bvm::Instruction(),
                         bvm::Instruction(),
                         bvm::Instruction(),
                     });

    std::cout << ntl::serialize(manager[0].at(0)) << std::endl;

    return 0;
}