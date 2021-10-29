#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2);
    int count = 0;
    int zerocount = 0;
    for(int i =0; i < lottos_len; i++)
    {
        if(lottos[i] == 0)
        {
            zerocount++;
            printf("zero count : %d\n", zerocount);
            continue;
        }
        for(int j =0 ; j < win_nums_len; j++)
        {
            if(lottos[i] == win_nums[j])
            {
                count++;
                printf("count : %d\n", count);
                break;
            }
        }

    }
    if(zerocount+count < 2)
    {
        answer[0] = 6;
    }
    else{
        answer[0]= 7 - (zerocount+ count);
    }
    if(count < 2)
    {
        answer[1] = 6;
    }
    else{
        answer[1] = 7-count;
    }
    return answer;
}


int main()
{
    int * answer;
    int lottos[6] = {44, 1, 0, 0, 31, 25};
    int lottos_len = 6;
    int win_nums[6] = {31, 10, 45, 1, 6, 19};
    int win_nums_len= 6;

    answer = solution(lottos,lottos_len,win_nums,win_nums_len);
    for(int i=0; i <2; i++)
    {
        printf("%d ", answer[i]);
    }
}