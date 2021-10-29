#include <iostream>
#include <cstdio>
int main()
{
    size_t n,m;
    scanf("%lu %lu", &n, &m);
    size_t *arr = new size_t[n];
    size_t min = 0;
    size_t max = 0;
    size_t result = 0;
    for(int i =0; i < n; i++)
    {
        scanf("%lu", arr+i);
        if(max < arr[i])
        {
            max = arr[i];
        }
    }

    while(1)
    {
        if(min > max) break;
        size_t middle = (max+min)/2;
        size_t temp = 0;
        for(int i =0; i < n ; i++)
        {
            signed long check = arr[i] - middle;
            if(check < 0)
            {
                continue;
            }
            else temp += (arr[i] - middle);
        }
        if(temp < m)
        {
            max = middle-1;

        }
        else
        {
            min = middle+1;
            result = middle;
        }
    }
    printf("%lu\n", result);
} 