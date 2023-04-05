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

    bvm::Function func(manager[0]);
    for (; !func.is_end(); func.forward())
        std::cout << ntl::serialize(func.get_instruction()) << std::endl;

    return 0;
}