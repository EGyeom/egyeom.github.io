#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    bool wait = false;
    int current_weight = 0;
    vector<int> truck_time;
    while(!truck_weights.empty())
    {
        if(wait)
        {
            
        }
        else
        {
            if(current_weight+ truck_weights[truck_time.size()] <= weight)
            {
                current_weight += truck_weights[truck_time.size()];
                truck_time.push_back(0);
            }
            else
            {
                wait = true;
            }
        }
        vector<int>::iterator it = truck_time.begin();
        for(it; it != truck_time.end(); ++it)
        {
            (*it)++;
        }
        if(truck_time[0] >= bridge_length)
        {
            current_weight -= truck_weights[0];
            if(current_weight < 0) current_weight = 0;
            truck_weights.erase(truck_weights.begin());
            truck_time.erase(truck_time.begin());
            if(wait) wait = false;
        }
        answer++;
    }
    answer++;
    return answer;
}
// bridge_length	weight	truck_weights	return
// 2	10	[7,4,5,6]	8
// 100	100	[10]	101
// 100	100	[10,10,10,10,10,10,10,10,10,10]	110
int main()
{
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weights = {10,10,10,10,10,10,10,10,10,10};

    printf("%d\n",solution(bridge_length,weight,truck_weights));
}