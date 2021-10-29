/* 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.  */

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <string.h>
void add(std::vector<int> set, int x)
{
    bool isfind = false;
    for(int i =0; i < set.size(); i++)
    {
        if(set.at(i) == x)
        {
            isfind = true;
            break;
        }
    }
    if(isfind == false)
    {
        set.push_back(x);
    }
}


int main()
{
    std::vector<int> set;

    int T;
    std::cin >> T;
    while(getchar() != NULL)
    for(int i = 0; i < T; i++)
    {
        char str[10];
        std::cin.getline(str,10,'\n');
        char * cmd = strtok(str," ");
        char * num = strtok(NULL," ");
        std::cout << cmd << "\n" << num << "\n";
        if(strcmp(cmd,"add")==0)
        {
            std::cout << "check 1" << "\n";
            //add(set,temp);
        }
        else if(strcmp(cmd,"remove")==0)
        {

        }
        else if(strcmp(cmd,"check")==0)
        {

        }
        else if(strcmp(cmd,"toggle")==0)
        {

        }
        else if(strcmp(cmd,"all")==0)
        {

        }
        else
        {
            set.clear();
        }
    }

}
