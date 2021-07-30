#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    long long temp= n;
    int len =0;
    while(temp != 0)
    {
        temp /= 10;
        len++;
    }
    int * answer = (int*)malloc(sizeof(int)*len);

    if(int i =0; i < len; i++)
    {
        answer[i] = n % 10;
        n = n/10;
    }  
}

int main()
{
    solution(12345);
}