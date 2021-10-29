// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;


// vector<string> solution(vector<string> orders, vector<int> course) {
//     vector<string> answer;
//     bool arr[26] = {0,};
//     int size = orders.size();
//     vector<vector<bool> > ordersVector(size, vector<bool>(26,0));
//     for(int i =0; i < size; i++)
//     {
//         int len = orders[i].size();
//         for(int j = 0; j < len; j++)
//         {
//             arr[orders[i][j]-'A'] = true;
//             ordersVector[i][orders[i][j]-'A'] = true;
//         }
//     }

//     int max = 0;

//     return answer;
// }

// int main()
// {
//     vector<string> temp = solution({"ABCFG","AC","CDE","ACDE","BCFG","ACDEH"},{2,3,4});

// }


#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int count[26] = {0,};
unordered_map<string,int> um;
string str[26][20];
void recursive(string order, int index, string temp)
{
    while(index <= order.size())
    {
        // if(temp.size() > 1)
        // {
        //     um[temp]++;
        //     count[temp.size()] = count[temp.size()] < um[temp] ? um[temp] : count[temp.size()];
        // }
        cout << temp << "\n";
        temp.push_back(order[index++]);
        recursive(order,index,temp);
        temp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(string i:orders)
    {
        sort(i.begin(), i.end());
        recursive(i,0, "");
    }

    return answer;
}

int main()
{
    vector<string> temp = solution({"ABCFG","AC","CDE","ACDE","BCFG","ACDEH"},{2,3,4});
    for(int i =0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << "\n";
}