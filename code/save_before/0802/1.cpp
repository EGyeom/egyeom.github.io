#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdio>
using namespace std;

int compare(const void * left, const void * right)
{
    int l = *(int*)left;
    int r = *(int*)right;

    if(l > r)
    {
        return -1;
    }
    else if(l < r)
    {
        return 1;
    }
    else return 0;
}

int solution(vector<int> priorities, int location) {

    int answer = 1;
    vector<int> ordered_priorities = priorities;
    qsort(&ordered_priorities[0],ordered_priorities.size(), sizeof(int),compare);
    int max = ordered_priorities[0];
    int index = 1;
    bool isLeft = false;
    while(ordered_priorities.size() != index)
    {
        if(ordered_priorities[index] == max)
        {
            ordered_priorities.erase(ordered_priorities.begin() + index);
        }
        else 
        {
            max=ordered_priorities[index++];
        }
    }
    index = 0;
    for(int i =0; i < ordered_priorities.size(); i++)
    {
        if(ordered_priorities[i] == priorities[location])
        {
            if(i == 0)
            {
                for(int j = 0; j < location; j++)
                {
                    if(priorities[j] == priorities[location])
                    {
                        answer++;
                    }
                }
                break;
            }
            else
            {
                index = i-1;
                int lastIndex =0;
                for(int j = 0; j < priorities.size(); j++)
                {
                    if(priorities[j] == ordered_priorities[index])
                    {
                        if(j > location)
                        {
                            isLeft = false;
                            lastIndex = j;
                        }
                        else
                        {
                            isLeft = true;
                            lastIndex = j;
                        } 
                    }
                }
                //printf("%d %d\n", isLeft, lastIndex);
                if(isLeft == false)
                {
                    for(int j = 0; j < location; j++)
                    {
                        if(priorities[j] == priorities[location])
                        {
                            answer++;
                        }
                    }
                    for(int j = lastIndex+1; j < priorities.size(); j++)
                    {
                        if(priorities[j] == priorities[location])
                        {
                            answer++;
                        }
                    }
                }
                else
                {
                    for(int j = lastIndex+1; j < location; j++)
                    {
                        if(priorities[j] == priorities[location])
                        {
                            answer++;
                        }
                    }
                }
                break;
            }
        }
        else
        {
            for(int j =0; j < priorities.size(); j++)
            {
                if(priorities[j] == ordered_priorities[i])
                {
                    answer++;
                }
            }

        } 
    }

    return answer;
}

// [2, 1, 3, 2]	2	1
// [1, 1, 9, 1, 1, 1]	0	5
int main()
{
    vector<int> v = {6,7,8,9,8,7,6};
    int num;
    for(int i =0 ; i < v.size(); i++)
    {
        printf("%d\n",solution(v,i));
    }
}