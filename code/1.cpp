#include <iostream>
#define __INT_MAX__ 0x7fffffff

int *arr;
int *sign;
int *check;
int *signArr;
int len;
int min=__INT_MAX__;
int max=-__INT_MAX__;
int n;
int signlen;
void function();

int main()
{
    std::cin >> n;
    
    arr = new int[n];
    sign = new int[n-1];
    signArr = new int[n-1];
    check = new int[n-1];

    for(int i =0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    for(int i = 0; i < 4; i++)
    {
        int temp = 0;
        std::cin >> temp;
        for(int j =0; j < temp; j++)
        {
            sign[signlen++] = i+1;
        }
    }

    function();

    std::cout << max << "\n" << min;
}

void function(){

    if(len == n-1)
    {
        int sum =0;
        sum = arr[0];
        for(int i = 0; i <n-1; i++)
        {
            switch (signArr[i])
            {
            case 1:
                sum = sum + arr[i+1];
                break;
            case 2:
                sum = sum - arr[i+1];
                break;
            case 3:
                sum = sum * arr[i+1];
                break;
            case 4:
                sum = sum / arr[i+1];
                break;
            }
        }
        if(max < sum)
        {
            max = sum;
        }
        if(min > sum)
        {
            min = sum;
        }
        return;
    }

    for(int i =0; i < n-1; i++)
    {
        if(check[i] == 0)
        {
            check[i] = 1;
            signArr[len++] = sign[i];
            function();
            check[i] = 0;
            len--;
        }
    }
    
    // for(int i =0 ; i < n; i++)
    // {
    //     std::cout << arr[i] << " ";
    //     if(i==n-1) break;
    //     switch (sign[i])
    //     {
    //     case 1:
    //         std::cout << "+ ";
    //         break;
    //     case 2:
    //         std::cout << "- ";
    //         break;
    //     case 3:
    //         std::cout << "* ";
    //         break;
    //     case 4:
    //         std::cout << "/ ";
    //         break;
    //     }
    // }


}