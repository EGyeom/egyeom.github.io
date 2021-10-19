#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solution(vector<vector<int> > routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), compare);
    int size = routes.size();
    int test = routes[0][1];
    for(int i =1; i < size; i++)
    {
        if(routes[i][1] < test)
        {
            test = routes[i][1];
        }
        else
        {
            if(routes[i][0] <= test)
            {
                continue;
            }
            else
            {
                test=routes[i][1];
                answer++;
            }
        }
    }
    //int i = index+1;
    // while(index <size)
    // {   
    //     int beforeSize = size;
    //     for(int i =0; i < size; i++)
    //     {
    //         cout << routes[i][0] << " " << routes[i][1] << "\n";
    //     }
    //     cout << routes[index][0] << " " << routes[index][1] << " " << routes[i][0] << " " << routes[i][1] << "\n";
    //     if((routes[index][0] <= routes[i][1]) && (routes[index][0] >= routes[i][0])
    //         || (routes[index][1] >= routes[i][0] && (routes[index][1] <= routes[i][1]))
    //         || ((routes[index][0] >= routes[i][0]) && (routes[index][1] <= routes[i][1])))
    //     {
    //         routes.erase(routes.begin()+i);
    //         break;
    //     }
    //     if(beforeSize != size)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         i++;
    //         if(i >= size)
    //         {
    //             index++;
    //             i = index+1;
    //         }
    //     }
    // }
    // while(index < size)
    // {
    //    bool isFind = false;
    //    for(int i =index+1; i<size; i++)
    //    {
    //        if((routes[index][0] <= routes[i][1]) && (routes[index][0] >= routes[i][0])
    //         || (routes[index][1] >= routes[i][0] && (routes[index][1] <= routes[i][1]))
    //        || ((routes[index][0] >= routes[i][0]) && (routes[index][1] <= routes[i][1])))
    //        {
    //            isFind= true;
    //            routes.erase(routes.begin()+i);
    //            break;
    //        }
    //    }
    //    if(isFind)
    //    {
    //        size = routes.size();
    //        continue;
    //    }
    //    else
    //    {
    //        index++;
    //    }
    // }
    return answer;

}

//[[-20,15], [-14,-5], [-18,-13], [-5,-3]]	2
int main()
{
cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }); //2
cout << endl;
cout << solution({ {-2, -1}, {1, 2}, {-3, 0} });//2
cout << endl;
cout << solution({ {0, 0}, });//1
cout << endl;
cout << solution({ {0, 1}, {0, 1}, {1, 2} });//1
cout << endl;
cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} });//4
cout << endl;
cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
cout << endl;
cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
cout << endl;
cout << solution({ {2,2},{0,1},{-10,9} });//2
cout << endl;
cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} });//4
cout << endl;
cout << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} });//2
cout << endl;
cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} });//8
cout << endl;
cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} });//2
cout << endl;
cout << solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }); // 2
cout << endl;
cout << solution({ {0,0},{0,0},{2,2}}); // 2
cout << endl;
cout << solution({ {0,1},{0,1},{2,2}}); // 2
cout << endl;
}

// print(solution([[-2,-1], [1,2],[-3,0]])) #2
// print(solution([[0,0],])) #1
// print(solution([[0,1], [0,1], [1,2]])) #1
// print(solution([[0,1], [2,3], [4,5], [6,7]])) #4
// print(solution([[-20,-15], [-14,-5], [-18,-13], [-5,-3]])) #2
// print(solution([[-20,15], [-14,-5], [-18,-13], [-5,-3]])) #2
// print(solution([[-20,15], [-20,-15], [-14,-5], [-18,-13], [-5,-3]])) #2

// 제가 처음에 잘못 푼 방법이 있는데 그 방법도 될 것 같다는 생각에 시도하면서 test case를 찾아봤습니다.
// {{0,2},{2,3},{3,4},{4,6}} 답은 2

// 추가로 아래 부분들은 질문게시판 내용들 모았습니다.

// cout << solution({ {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} }); //2
// cout << endl;
// cout << solution({ {-2, -1}, {1, 2}, {-3, 0} });//2
// cout << endl;
// cout << solution({ {0, 0}, });//1
// cout << endl;
// cout << solution({ {0, 1}, {0, 1}, {1, 2} });//1
// cout << endl;
// cout << solution({ {0, 1}, {2, 3}, {4, 5}, {6, 7} });//4
// cout << endl;
// cout << solution({ {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
// cout << endl;
// cout << solution({ {-20, 15}, {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} });//2
// cout << endl;
// cout << solution({ {2,2},{0,1},{-10,9} });//2
// cout << endl;
// cout << solution({ {-7, 0}, {-6, -4}, {-5, -3}, {-3, -1}, {-1, 4}, {1, 2}, {3, 4} });//4
// cout << endl;
// cout << solution({ {-5, -3}, {-4, 0}, {-4, -2}, {-1, 2}, {0, 3}, {1, 5}, {2, 4} });//2
// cout << endl;
// cout << solution({ {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}, {14, 15} });//8
// cout << endl;
// cout << solution({ {0, 12}, {1, 12}, {2, 12}, {3, 12}, {5, 6}, {6, 12}, {10, 12} });//2
// cout << endl;
// cout << solution({ {-191, -107}, { -184,-151 }, { -150,-102 }, { -171,-124 }, { -120,-114 } }); // 2
// cout << endl;