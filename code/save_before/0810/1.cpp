/*조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

조이스틱을 각 방향으로 움직이면 아래와 같습니다.

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동
예를 들어 아래의 방법으로 "JAZ"를 만들 수 있습니다.

- 첫 번째 위치에서 조이스틱을 위로 9번 조작하여 J를 완성합니다.
- 조이스틱을 왼쪽으로 1번 조작하여 커서를 마지막 문자 위치로 이동시킵니다.
- 마지막 위치에서 조이스틱을 아래로 1번 조작하여 Z를 완성합니다.
따라서 11번 이동시켜 "JAZ"를 만들 수 있고, 이때가 최소 이동입니다.
만들고자 하는 이름 name이 매개변수로 주어질 때, 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.

제한 사항
name은 알파벳 대문자로만 이루어져 있습니다.
name의 길이는 1 이상 20 이하입니다.
입출력 예
name	return
"JEROEN"	56
"JAN"	23
출처
"JEROEN", 56
"JAN", 23
"ABAAAAAAAAABB", 7
"AABAAAAAAABBB", 11
"BBBAAB", 9
"ZAAAZAAAAAA", 6
"NNAAAAANNN", 70
ZAAAZZZZZZZ
답 : 15
※ 공지 - 2019년 2월 28일 테스트케이스가 추가되었습니다.
*/
    // int wordDistance =0;
    // int locationDistance =0;
    // int currentCursor = 0;
    // int len = name.size();
    // int answer = 0;
    // int index =0;
    // int goRight =0;
    // int goLeft = 0;
    /*while(index < len)
    {
        int down = COUNT+UPPER - name.at(index);
        int up= name.at(index)- UPPER;
        if(up == 0)
        {
            index++;
            continue;
        }
        else if(down <= up)
        {
            wordDistance = down;
        }
        else wordDistance = up;
        goRight += wordDistance;
        int left = len + currentCursor - index;
        int right = index - currentCursor;
        if(right == 0)
        {
            index++;
            continue;
        }
        else if(left < right)
        {
            locationDistance = left;
            
        }
        else locationDistance = right;
        currentCursor = index++;
        goRight += locationDistance;
    }
    index =0;
    currentCursor =0;
    while(index < len)
    {   
        int number = (len - index)%len;
        int down = COUNT+UPPER - name.at(number);
        int up= name.at(number)- UPPER;
        if(up == 0)
        {
            index++;
            continue;
        }
        else if(down <= up)
        {
            wordDistance = down;
        }
        else wordDistance = up;
        goLeft += wordDistance;
        int left = (currentCursor+ len - number)% len;
        int right = (len - currentCursor + number) % len;
        if(left == 0)
        {
            index++;
            continue;
        }
        else if(left < right)
        {
            locationDistance = left;
        }
        else locationDistance = right;
        currentCursor = number;
        index++;
        goLeft += locationDistance;
    }
    if(goLeft <= goRight)
    {
        answer = goLeft;
    }
    else answer = goRight;
*/

#include <string>
#include <vector>
#include <stdio.h>
#define abs(X) (X) < 0 ? (X) * -1 : (X)
#define COUNT 26
#define UPPER 65
using namespace std;

int solution(string name) {

    int len = name.size();
    int currentCursor =0;
    int answer =0;

    int * arr = new int[len];
    for(int i =0; i < len; i++)
    {
        if(name.at(i) == UPPER)
        {
            arr[i] = 0;
        }
        else
        {
            int down = UPPER + COUNT - name.at(i);
            int up = name.at(i) - UPPER;
            if(down < up)
            {
                arr[i] = down;
            }
            else arr[i] = up;
        }
    }
    int index =1;
    while(1)
    {
        int isLeft = currentCursor - index;
        int isRight = currentCursor + index;

        if(arr[0] != 0)
        {
            answer += arr[0];
            arr[0] = 0;
        }
        if(isLeft< 0)
        {
            isLeft = len + isLeft;
        }

        if(isRight >= len)
        {
            isRight = isRight - len;
        }
        if(arr[isRight] != 0)
        {
            answer += arr[isRight];
            arr[isRight] = 0;
            answer += index;
            currentCursor = isRight;
            index =0;
        }
        else if(arr[isLeft] != 0)
        {
            answer += arr[isLeft];
            arr[isLeft] = 0;
            answer += index;
            currentCursor = isLeft;
            index =0;
        }

        if(isLeft == isRight)
        {
            break;
        }
        index++;
    }
    return answer;

}

int main()
{
    printf("%d\n",solution("ZAAAZZZZZZZ"));
}