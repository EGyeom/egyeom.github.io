#include <stdio.h>
#include <algorithm>
int main()
{
    int k,n;
    scanf("%d %d", &k, &n);
    size_t * arr = new size_t[k];
    size_t min = 1;
    size_t result = 0;
    size_t max = 0;
    for(int i =0; i < k; i++)
    {
        scanf("%ld", arr+i);
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    while(1)
    {
        size_t middle = (min+max)/2;
        size_t count = 0;
        for(int i =0; i < k; i++)
        {
            count += (arr[i]/middle);
        }
        if(count < n)
        {
            max = middle-1;
        }
        else
        {
            min = middle+1;
            result = middle;
        }
        if(min > max)
        {
            break;
        }
    }
    printf("%lu\n", result);
}