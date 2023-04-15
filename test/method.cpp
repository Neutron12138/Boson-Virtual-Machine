#include <iostream>
#include <ntl/NTL.hpp>
#include <ntl/NTL.cpp>

void a(const std::string&name)
{
    std::cout << name << std::endl;
}

int main()
{
    ntl::StaticMethod method = ntl::StaticMethod(a, 1);
    method.call<void,std::string>("aaa");
    return 0;
}
