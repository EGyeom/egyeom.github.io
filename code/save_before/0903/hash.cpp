#include <iostream>
#include <cstdio>
#include <string.h>

#define R 31
#define M 1234567891

int main()
{
    int len = 0;
    scanf("%d", &len);
    char * string = new char[len+1];
    scanf("%s", string);
    long long result = 0;
    long long multiply =1;
    for(int i=0; i <len; i++)
    {
        result = (result + (string[i]-'a'+1)*multiply) % M;

        multiply = (multiply * R)% M;
    }
    printf("%lld\n", result);
}