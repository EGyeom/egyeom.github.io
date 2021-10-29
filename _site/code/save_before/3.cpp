#include <iostream>
#include <deque>

std::deque<int> dq;

int function_find(int num)
{
    int result = 0;
    for(auto iter = dq.begin(); iter != dq.end(); ++iter)
    {
        if(*iter == num)
        {
            result = iter - dq.begin();
        }
    }

    return result;
}

void toRight()
{
    int temp =0;
    temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
}

void toLeft()
{
    int temp =0;
    temp = dq.front();
    dq.pop_front();
    dq.push_back(temp);
}

int main()
{
    int n,m;
    int count = 0;
    std::cin >> n >> m;
    for(int i=1 ; i<=n;i++)
    {
        dq.push_back(i);
    }

    for(int i =0; i < m; i++)
    {
        int temp = 0;
        std::cin >> temp;
        int distance = function_find(temp);
        if(distance == 0)
        {
            dq.pop_front();
            continue;
        }
        else if(distance <= (dq.size()/2))
        {
            while(1)
            {   
                count++;
                toLeft();
                if(dq.front() == temp)
                {
                    dq.pop_front();
                    break;
                } 
            }
        }
        else
        {
            while (1)
            {
                count++;
                toRight();
                if(dq.front() == temp)
                {
                    dq.pop_front();
                    break;
                } 
            }
        }
    }
    std::cout << count << "\n";
}