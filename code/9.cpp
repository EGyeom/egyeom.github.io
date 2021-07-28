#include <cstdio>
using namespace std;

long long crushed(long w, long h)
{
    if(w == h)
    {
        return w;
    }
    else if(w%2 == 0 && h%2 == 0)
    {
        return 2*crushed(w/2,h/2);
    }
    else return  w+h-1;
}

long long solution(long w,long h) {
    long long answer = 0;
    answer = w*h -crushed(w,h);
    return answer;
}


int main()
{
    while(1)
    {
        int m,n;
        scanf("%d %d", &m, &n);
        printf("%lld\n", solution(m,n));
    }

}