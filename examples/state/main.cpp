#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

int main()
{
    bvm::BasicState state;

    state.add_function(1, bvm::InstructionContainer());
    state.call_function(1);

    return 0;
}