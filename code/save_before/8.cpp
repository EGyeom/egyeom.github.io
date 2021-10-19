#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 0;
    for(int i =0; i<signs_len; i++)
    {
        if(signs[i] == true)
        {
            answer += absolutes[i];
        }
        else
        {
            answer -= absolutes[i];
        }
    }
    return answer;
}


int main()
{
    int a = 10;
    int b = 5;
    int result = 0;
    a > 1 ? a > 5 ? b > 11 ? result = 4 : result = 3 : result = 2 : result = 1;

    printf("%d\n", result);
}