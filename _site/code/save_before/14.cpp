// 문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
// s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.

// 제한 사항
// str은 길이 1 이상인 문자열입니다.
// 입출력 예
// s	return
// "Zbcdefg"	"gfedcbZ"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *check1, const void *check2)
{
    char c1 = *(char*)check1;
    char c2 = *(char*)check2;

    if(c1 < c2)
    {
        return 1;
    }
    else if (c1 > c2)
    {
        return -1;
    }
    else return 0;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(len+1);
    memset(answer,0,len+1);
    strcpy(answer,s);
    qsort(answer,len,sizeof(char),compare);
    return answer;
}


int main()
{
    printf("%s\n",solution("Zbcdefg"));
}