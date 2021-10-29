using namespace std;

long long find(long long w, long long h)
{
    if(w % h == 0) return h;
    else
    {
        if(h == 1) return 1;
        else
        {
            return find(h,w%h);
        } 
    }
}

long long solution(int w,int h) {
    long long answer = 0;
    long long w1 = (long long)w;
    long long h1 = (long long)h;
    if(h1 > w1)
    {
        w1 ^= h1;
        h1 ^= w1;
        w1 ^= h1;
    }
    long long common_factor = find(w1,h1);
    answer = w1*h1 - (w1/common_factor + h1/common_factor -1)*common_factor;
    return answer;
}