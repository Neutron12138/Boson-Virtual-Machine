#include <iostream>
#include "../../src/BVM.hpp"
#include "../../src/BVM.cpp"

int main()
{
    bvm::MemoryManager manager;

    bvm::Memory mem(8);
    mem.get<int>(0) = 666;
    mem.get<int>(4) = 999;
    manager.add_item(0, mem);

    std::cout << manager[0].get<long long>(0) << std::endl;

    return 0;
}