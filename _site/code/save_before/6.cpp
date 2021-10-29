#include <string>
#include <vector>
#include <cstdio>
#include <string.h>
using namespace std;
#define WORDS_MAX 10
const char * words[WORDS_MAX]={
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int solution(string s) {
    vector<int> v;
    int answer = 0;
    int count = 0;
    int check = 0;

    while(1)
    {
        if(count >= s.size())
        {
            break;
        }
        if(s.at(count) >= '0' && s.at(count) <= '9')
        {
            int num = s.at(count++) - '0';
            v.push_back(num);
        }
        else
        {   
            for(int index =3; index<=5; index++)
            {
                for(int i= 0 ; i < WORDS_MAX; i++)
                {
                    if(strlen(words[i]) == index)
                    {
                        if(s.compare(count,index,words[i])==0)
                        {
                            v.push_back(i);
                            count = count+index;
                        }
                    }
                    else continue;
                }
            }

        }
    }

    int multiple =1;
    while(!v.empty())
    {
        answer += v.back() * multiple; 
        v.pop_back();
        multiple *= 10;
    }
    return answer;
}

int main()
{
    
   int result = solution("one2twothree");

    printf("%d\n", result);

}