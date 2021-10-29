#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    for(int i =2; i <n; i++)
    {
        if(n % i == 0)
        {
            answer += i;
        }
    }
    answer += 1+n;
    return answer;
}