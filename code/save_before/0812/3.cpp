// 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
// 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
// 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
// 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
// 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
// 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
//      만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
// 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
// no	new_id	result
// 예1	"...!@BaT#*..y.abcdefghijklm"	"bat.y.abcdefghi"
// 예2	"z-+.^."	"z--"
// 예3	"=.="	"aaa"
// 예4	"123_.def"	"123_.def"
// 예5	"abcdefghijklmn.p"	"abcdefghijklmn"

#include <string>
#include <vector>
#include <iostream>
#define UPPER_START 65
#define UPPER_END 90
#define UNDER_START 97
#define UNDER_END 122
#define NUMBER_START 48
#define NUMBER_END  57
#define MINUS  45
#define UNDERLINE  95
#define DOT 46


using namespace std;

void step_one(string& new_id,int size, string& answer)
{
    for(int i =0; i < size; i++)
    {
        if(answer.size() >= 15)
        {
            break;
        }
        if(new_id.at(i) >= UPPER_START && new_id.at(i) <= UPPER_END)
        {
            answer.push_back(new_id.at(i) + 32);
        }
        else if(new_id.at(i) >= NUMBER_START && new_id.at(i) <= NUMBER_END)
        {
            answer.push_back(new_id.at(i));
        }
        else if(new_id.at(i) == MINUS)
        {
            answer.push_back(new_id.at(i));
        }
        else if(new_id.at(i) == UNDERLINE)
        {
            answer.push_back(new_id.at(i));
        }
        else if( new_id.at(i) == DOT)
        {
            if(answer.size() == 0)
            {
                continue;
            }
            else if(answer.at(answer.size()-1) == DOT)
            {
                continue;
            }
            else answer.push_back(new_id.at(i));
        }
        else if(new_id.at(i) >= UNDER_START && new_id.at(i) <= UNDER_END)
        {
            answer.push_back(new_id.at(i));
        }
        else
        {
            continue;
        }
    }
    if(answer.size() == 0)
    {
        answer.push_back('a');
    }
    else if(answer.at(answer.size()-1) == DOT)
    {
        answer.erase(answer.begin() + answer.size()-1);
    }

    if(answer.size() <= 3)
    {
        char temp = answer[answer.size()-1];
        while(answer.size() != 3)
        {
            answer.push_back(temp);
        }
    }
}

string solution(string new_id) {
    string answer = "";
    int size = new_id.size();
    step_one(new_id,size,answer);
    return answer;
}

int main()
{
    cout << solution("abcdefghijklmn.p") << "\n";

}