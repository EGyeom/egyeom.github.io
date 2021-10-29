#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b)
{
    int ma = *(int*)a;
    int mb = *(int*)b;
    char ab[9] = "";
    char ba[9] = "";

    char tempA[5];
    char tempB[5];

    sprintf(tempA,"%d",ma);
    sprintf(tempB,"%d",mb);

    strcat(ab,tempA);
    strcat(ab,tempB);

    strcat(ba,tempB);
    strcat(ba,tempA);

    return strcmp(ba,ab);
}

char* solution(int numbers[], size_t numbers_len) {

    char * answer;
    qsort(numbers,numbers_len,sizeof(int),compare);

    if(numbers[0]==0)
    {
        answer = (char*)malloc(2);
        memset(answer,0,sizeof(answer));
        strcat(answer,"0");
        return answer;
    }
    answer = (char*)malloc(4*numbers_len);
    memset(answer,0,sizeof(answer));

    for(int i=0; i < numbers_len; i++)
    {
        printf("%d ", numbers[i]);
    }
    for(int i =0; i <numbers_len; i++)
    {
        char temp[5] ="";
        sprintf(temp, "%d", numbers[i]);
        strcat(answer,temp);
    }
    return answer;
}

int main()
{
    int arr[] ={404,40, 101, 10, 999, 909, 9, 99};
    printf("%s\n",solution(arr,sizeof(arr)/sizeof(int)));
}