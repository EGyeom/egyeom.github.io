#include <iostream>

enum basis{
    A=15,
    B=28,
    C=19,
};

int main()
{
    int a,b,c;
    std::cin >> a >> b >> c;
    int count = a;
    while(1)
    {
        int tempA = (count % A == 0) ? A : count % A;
        int tempB = (count % B == 0) ? B : count % B;
        int tempC = (count % C == 0) ? C : count % C;
        if(tempA == a && tempB == b && tempC == c)
        {
            break;
        }
        else
        {
            count += A;
        }
    }
    std::cout << count << "\n";

}