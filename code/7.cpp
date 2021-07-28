#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int * check;

bool primeCheck(int nums[], size_t nums_len)
{
    int temp = 0;
    for(int i =0; i <nums_len; i++)
    {
        if(check[i] == 1)
        {
            temp += nums[i];
        }
    }

    for(int i =2; i < temp; i++)
    {
        if(temp % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void function(int nums[], size_t nums_len, int min, int * count, int * primeCount)
{
    if(*count == 3)
    {
        if(primeCheck(nums,nums_len))
        {
            (*primeCount)++;
        }
        return;
    }

    for (int i = min; i < nums_len; i++)
    {
        if(check[i] == 0)
        {
            (*count)++;
            check[i] = 1;
            function(nums,nums_len,i,count,primeCount);
            check[i] = 0;
            (*count)--;
        }
    }
    
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = -1;
    check = (int*)malloc(nums_len);
    int count=0;
    int primeCount=0;
    for(int i =0; i < nums_len; i++)
    {
        if(check[i] == 0)
        {
            count++;
            check[i] = 1;
            function(nums, nums_len ,i, &count, &primeCount);
            check[i] = 0;
            count--;
        }
    }
    answer = primeCount;
    return answer;
}

int main()
{
    int nums[] = {1,2,6,7,4};
    int result = solution(nums,sizeof(nums)/sizeof(int));
    printf("%d\n", result);
}