#include <iostream>
#include <string.h>
#include <deque>
#include <string>
#include <algorithm>

char cmd[100000];
std::deque<int> dq;

void func(bool reverse){
    if(reverse)
    {
        dq.pop_back();
    }
    else
    {
        dq.pop_front();
    }
}

int main()
{
    int t=0;
    std::cin >> t;
    for(int i = 0; i < t ; i++)
    {
        dq.clear();
        bool result = true;
        std::cin >> cmd;
        int len = strlen(cmd);
        int num=0;
        bool reverse = false;
        std::cin >> num;
        std::string str;
        std::cin >> str;
        int startIndex = 1;
        int endIndex = str.size();

        while(1)
        {
            int check = startIndex;
            while(str[check]!=',' && str[check] != ']')
            {
                check++;
            }
            if(check != startIndex)
            {
                dq.push_back(std::atoi(str.substr(startIndex, check-1).c_str()));
                startIndex = check+1;
                if(startIndex >= endIndex) break;
            }
            else
            {
                break;
            }
        }
        for (int j =0; j < len; j++)
        {
            if(dq.empty() == true)
            {
                result = false;
                break;
            } 
            if(cmd[j] == 'R' && reverse == false)
            {
                reverse = true;
            }
            else if(cmd[j] == 'R' && reverse == true)
            {
                reverse = false;
            }
            else func(reverse);
        }
        if(result == true)
        {
            std::deque<int>::iterator it;
            {
                std::cout <<"[";
                while(1)
                {
                    if(reverse == true)
                    {
                        std::cout << dq.back();
                        dq.pop_back();
                    }
                    else
                    {
                        std::cout << dq.front();
                        dq.pop_front();
                    }
                    if(dq.empty() == true)
                    {
                        break;
                    }
                    else std::cout << ",";
                }
                std::cout <<"]" << "\n";
            }

        }
        else std::cout << "error" << "\n";
    }
}