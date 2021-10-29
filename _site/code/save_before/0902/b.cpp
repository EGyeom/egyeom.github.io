/* 
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
 */
    // if(start > end) return start;
    // if(strncmp(type,"upper",5) == 0)
    // {
    //     if(v[index] > number)
    //     {
    //        return FindNumber(start, index-1, v, number, type);
    //     }
    //     else
    //     {
    //        return FindNumber(index+1, end, v, number, type);
    //     }
    // }
    // else
    // {
    //     if(v[index] >= number)
    //     {
    //        return FindNumber(start, index-1, v, number, type);
    //     }
    //     else
    //     {
    //        return FindNumber(index+1, end, v, number, type);
    //     }
    // }
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <time.h>
#include <cstdio>
int FindNumber(int start, int end, int * v, int number, const char * type)
{
    while(start <= end)
    {
        int index = (end + start)/2;
        if(strncmp(type,"upper",5) == 0)
        {
            if(v[index] > number)
            {
                end = index -1;
            }
            else
            {
                start = index +1;
            }
        }
        else
        {
            if(v[index] >= number)
            {
                end = index -1;
            }
            else
            {
                start = index +1;
            }
        }
    }
    return start;
}

int main()
{
    int N,M;
    std::cin >> N;
    int * nVector = new int[N];
    for(int i =0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        nVector[i] = temp;
    }
    std::sort(nVector, nVector+N);
    std::cin >> M;
    for(int i =0; i < M; i++)
    {
        int temp;
        int lowerBound = 0;
        int upperBound = 0;
        scanf("%d", &temp);
        upperBound = FindNumber(0,N-1, nVector, temp, "upper");
        lowerBound = FindNumber(0,N-1, nVector, temp, "lower");;
        printf("%d ", upperBound - lowerBound);
    }
    printf("\n");
}


    // std::vector<int> v = {1,2,3,4,5,6,7,8,9};

    // std::cout << v.size() << "\n";
    // std::cout << FindNumber(0,v.size()-1,v,6) << "\n";