#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num) {
    int answer = 0;
    while(num != 1)
    {
        if(answer== 500)
        {
            answer = -1;
            break;
        }
        answer += 1;
        if(num % 2 ==0)
        {
            num /= 2;
        }
        else
        {
            num = num*3;
            num += 1;
        }
        printf("%d\t%d\n", num,answer);
    }
    
    return answer;
}

int main()
{
    int n;
    while (1)
    {
    scanf("%d", &n);
    solution(n);
    }
}