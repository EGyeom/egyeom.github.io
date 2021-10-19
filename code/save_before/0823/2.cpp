// 다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
// 다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
// 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
#include <iostream>
#include <vector>
#include <string>

typedef struct _NUM{
    bool isUse;
    int num;
} NUM;

typedef struct _NUMS{
    NUM num[10];
    static int count;
}NUMS;

int NUMS::count = 0;

void initNums(NUMS * nums){

    for(int i =0; i < 10; i++)
    {
        nums->num[i].num = i;
        nums->num[i].isUse = false;
    }
}

int main()
{
    std::vector<NUMS> v;
    std::string input;
    
    std::cin >> input;

    for(int i =0; i < input.size(); i++)
    {
        if(v.empty())
        {
            NUMS tempNums;
            initNums(&tempNums);
            v.push_back(tempNums);
            NUMS::count++;
        }
        int temp = input.at(i) - '0';
        bool isfind = false;
        for(int j =0; j < v.size(); j ++)
        {
            if(v[j].num[temp].isUse == true)
            {
                if(temp == 6)
                {
                    if(v[j].num[9].isUse == true)
                    {

                    }
                    else
                    {
                        v[j].num[9].isUse = true;
                        isfind = true;
                        break;
                    }
                }
                else if(temp == 9)
                {
                    if(v[j].num[6].isUse == true)
                    {

                    }
                    else
                    {
                        v[j].num[6].isUse = true;
                        isfind = true;
                        break;
                    }
                }

            }
            else
            {
                v[j].num[temp].isUse = true;
                isfind = true;
                break;
            }           
        }
        if(isfind == false)
        {
            NUMS tempNums;
            initNums(&tempNums);
            tempNums.num[temp].isUse = true;
            v.push_back(tempNums);
            NUMS::count++;
        }
    }
    std::cout << NUMS::count <<"\n";
}