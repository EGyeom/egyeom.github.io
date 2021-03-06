/* 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다. */

#include <iostream>
#include <cstdio>
#include <string.h>

int queue[10000];
int front =0;
int back = 0;
void push(int x);
int pop();
int size();
bool empty();

int main()
{
    int N;
    scanf("%d", &N);
    for(int i =0; i < N; i++)
    {
        char cmd[6];
        memset(cmd,0,sizeof(cmd));
        scanf("%s", cmd);
        if(strncmp(cmd,"push",4)==0)
        {
            int num;
            scanf("%d", &num);
            push(num);
        }
        else if(strncmp(cmd,"pop",3)==0)
        {
            printf("%d\n", pop());
        }
        else if(strncmp(cmd,"size",4)==0)
        {
            printf("%d\n",size());
        }
        else if(strncmp(cmd,"empty",5)==0)
        {
            printf("%d\n", empty());
        }
        else if(strncmp(cmd,"front",5)==0)
        {
            if(empty())
            {
                printf("%d\n",-1);
            }
            else printf("%d\n", queue[front]);
        }
        else if(strncmp(cmd,"back",4)==0)
        {
            if(empty())
            {
                printf("%d\n",-1);
            }
            else printf("%d\n", queue[back-1]);
        }
    }

}

void push(int x)
{
    queue[back++] = x;
}

int pop()
{
    if(empty())
    {
        return -1;
    }
    else return queue[front++];
}

int size()
{
    return back - front;
}

bool empty()
{
    if(front == back)
    {
        return true;
    }
    else return false;
}
