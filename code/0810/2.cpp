#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(number);
    char* answer = (char*)malloc(sizeof(char)* (len+1-k));
    memset(answer, 0, sizeof(char) * (len+1-k));
    int deleteCount = 0;
    int currentPos = 0;
    int maxIndex = 0;
    int answerIndex =0;
    int max = number[maxIndex];
    while(1)
    {   
        max = number[currentPos];
        maxIndex = currentPos;
        for(int i =currentPos+1; i <= currentPos + k - deleteCount; i++)
        {
            if(max < number[i])
            {
                max = number[i];
                maxIndex = i;
            }
        }
        if(maxIndex == currentPos)
        {
            if(len-currentPos == k - deleteCount)
            {
                break;
            }
            currentPos++;
            answer[answerIndex++] = number[maxIndex];
            continue;
        }
        deleteCount += maxIndex - currentPos;
        currentPos = maxIndex;
        if(deleteCount == k)
        {
            for(int i = currentPos; i < len; i++)
            {
                answer[answerIndex++] = number[i];
            }
            break;
        }
        else
        {
            answer[answerIndex++] = number[currentPos];
        }
        currentPos++;
    }
    return answer;
}

int main()
{
    const char * number = "77777777";
    printf("%s\n", solution(number,2));
}