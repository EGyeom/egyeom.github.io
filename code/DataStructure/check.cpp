#include <iostream>
#include <string.h>

int main()
{
    int t;
    std::cin >> t;
    std::cin.ignore();
    char temp[10];
    std::cin.getline(temp,10,'\n');
    std::cout << temp << "\n";
}