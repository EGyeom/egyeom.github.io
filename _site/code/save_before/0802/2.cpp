// [93, 30, 55]	[1, 30, 5]	[2, 1]
// [95, 90, 99, 99, 80, 99]	[1, 1, 1, 1, 1, 1]	[1, 3, 2]

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain;
    int size = progresses.size();
    int count = 0;
    for(int i =0; i < size; i++)
    {
        int value = (100-progresses[i])/speeds[i];
        if((100-progresses[i])% speeds[i] == 0)
        {
            remain.push_back(value);
        }
        else
        {
            remain.push_back(value+1);
        }
    }
    while(!remain.empty())
    {
        while(remain[0] <= 0)
        {
            remain.erase(remain.begin());
            count++;
        }

        for(int i= 0; i < remain.size(); i++)
        {
            remain[i]--;
        }
    }

    return answer;
}

int main()
{
    vector<int> progress = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    vector<int> result = solution(progress,speeds);

    for(int i =0; i < result.size(); i++)
    {
        printf("%d ",result[i]);
    }
    printf("\n");
}