#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int sign = 1;
    int answer = 0;
    if(s[0] >= '0' && s[0] <= '9')
    {
        answer += atoi(s);
    }
    else
    {
        if(s[0]=='-')
        {
            sign =-1;
        }  
        answer += atoi(s+1);
        answer *= sign;
    }
    return answer;
}

int main()
{

    printf("%d\n", solution("-1234"));

}