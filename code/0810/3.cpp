// people	limit	return
// [70, 50, 80, 50]	100	3
// [70, 80, 50]	100	3

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit)
{  
    sort(people.begin(), people.end(), greater<int>());
    int front = 0;
    int back = people.size()-1;
    int answer =0;
    while(front < back)
    {
        if(people[front] + people[back] <= limit)
        {
            answer++;
            front++;
            back--;
        }
        else{
            front++;
            answer++;
        }
        if(front==back)
        {
            answer++;
        }
    }
    return answer;
}


int main()
{//[10,20,30,40,50,60,70,80,90], 100 => 5
    vector<int> v = {10,20,30,40,50,60,70,80,90};
    int limit = 100;
    printf("%d\n", solution(v,limit));
}


// #include <string>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int solution(vector<int> people, int limit)
// {  
//     sort(people.begin(), people.end());
//     int answer =0;
//     while(!people.empty())
//     {   
//         int size = people.size();
//         int min = limit;
//         int minIndex = 0;
//         for(int i = 1; i < size; i++)
//         {
//             int temp = people[0];
//             temp += people[i];
//             if(temp > limit)
//             {
//                 continue;
//             }
//             else
//             {
//                 if(min > limit-temp)
//                 {
//                     min = limit - temp;
//                     minIndex = i;
//                 }
//             }
//         }
//         if(minIndex == 0)
//         {
//             people.erase(people.begin());
//             answer++;
//         }
//         else
//         {
//             people.erase(people.begin()+ minIndex);
//             people.erase(people.begin());
//             answer++;
//         }
//     }
//     return answer;
// }
