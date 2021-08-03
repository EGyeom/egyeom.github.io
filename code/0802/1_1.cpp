#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdio>
using namespace std;

int compare(pair<int,int> a, pair<int,int> b)
{
    return a.first > b.first;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    vector<pair<int,int> > v;
    int size = priorities.size();
    vector<pair<int,int> > set;
    for(int i =0; i < size; i++)
    {
        v.push_back(make_pair(i,priorities[i]));
        bool multiCheck = false;
        for(int j = 0; j < set.size(); j++)
        {
            if(set[j].first == priorities[i])
            {
                multiCheck = true;
                set[j].second++;
            }
        }
        if(multiCheck == false)
        {
            set.push_back(make_pair(priorities[i],1));
        }
    }
    sort(set.begin(),set.end(), compare);

    int lastIndex = 0;
    int setIndex =0;
    int count = 0;

    while (1)
    {   
        if(v[lastIndex].second != set[setIndex].first)
        {
            pair<int,int> temp = v[lastIndex];
            v.erase(v.begin()+lastIndex);
            v.push_back(temp);
        }
        else
        {
            count++;
            lastIndex++;
            if(count == set[setIndex].second)
            {
                count = 0;
                setIndex++;
                if(setIndex == set.size())
                    break;
            }
        }
    }

    for(int i =0; i < size; i++)
    {
        if(v[i].first == location)
        {
            break;
        }
        else answer++;
    }
    return answer;
}


int main()
{
    vector<int> v = {2,1,2,1,2};
    int num = 0;
    //while(1)
    //{
    //scanf("%d", &num);
    printf("%d\n",solution(v,0));
    //}
}