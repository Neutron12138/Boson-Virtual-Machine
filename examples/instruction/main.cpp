#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

int main()
{
    bvm::InstructionManager manager;
    manager
        .add_item(0, bvm::InstructionContainer{
                         bvm::Instruction(
                             bvm::Command::MakeTemp,
                             8),
                         bvm::Instruction(
                             bvm::Command::Move,
                             bvm::CommandFlag::DWord,
                             bvm::CommandFlag::RAX),
                         bvm::Instruction(
                             bvm::Command::NativeCall),
                     });

    bvm::Function func(manager[0]);
    for (; !func.is_end(); func.backward())
        std::cout << ntl::serialize(func.get_instruction()) << std::endl;

    return 0;
}