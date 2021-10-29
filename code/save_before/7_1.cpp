#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(int num){
    for(int i=2; i < num; i++)
    {
        if(num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    int count = 0;
    int temp = 0;
    for(int i =0; i < nums_len-2; i++)
    {
        for(int j =i+1 ; j < nums_len-1; j++)
        {
            for(int k=j+1; k < nums_len; k++)
            {
                temp += nums[i] + nums[j] + nums[k];
                if(isPrime(temp))
                {
                    answer++;
                }
                temp = 0;
            }
        }
    }
    return answer;
}

int main()
{
    int arr[] = {1,2,6,7,4};
    printf("%d\n", solution(arr,sizeof(arr)/sizeof(int)));
}