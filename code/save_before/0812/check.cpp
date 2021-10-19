#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int compare(vector<int> a, vector<int> b)
{
    int distanceA = a[1] - a[0];
    int distanceB = b[1] - b[0];

    if(distanceA < distanceB)
    {
        return 1;
    }
    else return 0;

    //return distanceA < distanceB;
}

int main()
{
    vector<vector<int> > v1 = {{-2,-1},{1,2},{-3,0}}; 
    sort(v1.begin(), v1.end(), compare);

    for(int i =0; i < v1.size(); i++)
    {
        printf("%d %d\n", v1[i][0], v1[i][1]);
    }
}