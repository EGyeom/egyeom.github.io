#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
//numbers 0~1000
//numbers_len 1~100000
// numbers_len은 배열 numbers의 길이입니다.

int itoa(int number, char * buf)
{
    int count = 0;
    int temp = number;
    int i =0;
    if(number == 0)
    {
        buf[0] = '0';
        return 1;
    }
    while(temp !=0)
    {
        temp /= 10;
        count++;
    }
    temp = number;
    while(temp != 0)
    {
        buf[count-(i++)-1] = temp % 10 + '0';
        temp = temp / 10;
    }
    return count;
}

char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char ** cNumber = (char**)malloc(sizeof(char*) * numbers_len);
    int total_len = 0;
    int zero_check =0;
    int * cNumber_count = (int*)malloc(sizeof(int)* numbers_len);
    memset(cNumber,0,sizeof(cNumber));
    memset(cNumber_count,0,sizeof(cNumber_count));
    for(int i=0; i < numbers_len; i++)
    {
        cNumber[i] = (char*)malloc(4);
        memset(cNumber[i], 0 , sizeof(cNumber[i]));
        cNumber_count[i] = itoa(numbers[i],cNumber[i]);
        if(numbers[i] == 0)
        {
            zero_check++;
        }
        total_len += cNumber_count[i];
    }
    //sort
   for(int i = 0 ; i < 4; i++)
   {
       for(int j =0; j <numbers_len-1; j++)
       {
           for(int k =j+1; k < numbers_len; k++)
            {
                if(cNumber[j][i] < cNumber[k][i])
                {
                    if(cNumber[j][i] == NULL)
                    {
                        if(i<=2)
                        {
                            if(i == 2)
                            {
                                if(cNumber[j][i-1] == NULL) continue;
                                if(cNumber[j][0] <= cNumber[k][i])
                                {
                                    //pass
                                }
                                else continue;
                            }
                            else continue;
                        } 
                    }
                    char * tempChar = cNumber[j];
                    cNumber[j] = cNumber[k];
                    cNumber[k] = tempChar;

                    int tempNum = cNumber_count[j];
                    cNumber_count[j] = cNumber_count[k];
                    cNumber_count[k] = tempNum;
                }
                else if(cNumber[j][i] > cNumber[k][i])
                {
                    if(cNumber[k][i] == NULL)
                    {
                        if(i<=1)
                        {
                            if(cNumber[j][i] <= cNumber[k][0])
                            {
                                char * tempChar = cNumber[j];
                                cNumber[j] = cNumber[k];
                                cNumber[k] = tempChar;

                                int tempNum = cNumber_count[j];
                                cNumber_count[j] = cNumber_count[k];
                                cNumber_count[k] = tempNum;
                            } 
                        }
                    }
                }
           }
       }
  }
    char* answer = (char*)malloc(total_len);
    memset(answer,0,sizeof(answer));
    if(zero_check == numbers_len)
    {
        answer[0] = '0';
    }
    else
    {
        for(int i =0; i < numbers_len; i++)
        {
            strncat(answer,cNumber[i],cNumber_count[i]);
        }
    }

    return answer;
}
int main()
{
    int arr[] = {40,404};
    //char * test = (char*)malloc(6);
    //printf("%s", test);
    printf("%s\n", solution(arr,sizeof(arr)/sizeof(int)));
}