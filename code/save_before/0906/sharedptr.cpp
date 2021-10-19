#include <iostream>
#include <memory>

int main()
{
    int a = 10;
    std::shared_ptr<int> ptr(a);
    std::cout << *ptr << "\n";
}