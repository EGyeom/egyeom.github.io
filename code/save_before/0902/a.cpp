#include <iostream>

int main()
{
    while(1)
    {
        int input = 0;
        int length = 0;
        std::cin >> input;
        if(input == 0) break;
        int temp =input;
        while(temp != 0)
        {
            length++;
            temp = temp / 10;
        }
            bool isSame = true;
            int * arr = new int[length];
            int * reverse = new int[length];
            for(int i =0; i < length; i++)
            {
                arr[i] = input % 10;
                reverse[length-1-i] = input%10;
                input = input / 10;
            }

            for(int i =0; i < length; i++)
            {
                if(arr[i] != reverse[i])
                {
                    isSame = false;
                    break;
                }
            }
            if(isSame) std::cout << "yes\n";
            else std::cout << "no\n";

    }
}