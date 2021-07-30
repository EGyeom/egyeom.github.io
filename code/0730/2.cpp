// 임의의 양의 정수 n에 대해, n이 어떤 양의 정수 x의 제곱인지 아닌지 판단하려 합니다.
// n이 양의 정수 x의 제곱이라면 x+1의 제곱을 리턴하고, n이 양의 정수 x의 제곱이 아니라면 -1을 리턴하는 함수를 완성하세요.

// 제한 사항
// n은 1이상, 50000000000000 이하인 양의 정수입니다.
// 입출력 예
// n	return
// 121	144
// 3	-1
// 입출력 예 설명
// 입출력 예#1
// 121은 양의 정수 11의 제곱이므로, (11+1)를 제곱한 144를 리턴합니다.

// 입출력 예#2
// 3은 양의 정수의 제곱이 아니므로, -1을 리턴합니다.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long function(long long n, long long current, long long before)
{
    if(n==1) return 1;
    if(n == (current * current))
    {
        return current;
    }
    else if(current == before)
    {
        return 0;
    }
    else if( n > (current* current))
    {   
        if((current+before)/2 > current)
        {
            return function(n,(current+before)/2, before);
        }
        return function(n,(current+before)/2, current);
    }
    else if( n < (current* current))
    {
        return function(n, current/2, current);
    }
}

long long solution(long long n) {
    long long answer = 0;
    long long temp = function(n,0,n);
    if(temp == 0)
    {
        answer = -1;
    }
    else
    {
        answer = (temp+1)*(temp+1);
    }
    return answer;
}


int main()
{
    int n;
    while ((1))
    {
        scanf("%d", &n);
        printf("%lld\n",solution(n));
    }
    
}