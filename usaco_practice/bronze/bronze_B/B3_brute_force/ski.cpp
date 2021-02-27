// Ski course design
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int hills[1000]={};
    int max=0, min=1000; 
    for (int i=0; i<N; i++)
    {
        cin >> hills[i];
        if (hills[i]<min)
        {
            min=hills[i];
        }
        if (hills[i]>max)
        {
            max=hills[i];
        }
    }
    //going over 
    int cost=99999999;
    for (int j=0; j<=max-17; j++)
    {
        int cost1=0;
        // from j to j+17...
        for (int k=0; k<N; k++)
        {
            if (hills[k]<j)
            {
                cost1 += (j-hills[k]) * (j-hills[k]);
            }
            else if (hills[k]>j+17)
            {
                cost1 += (hills[k]-j-17) * (hills[k]-j-17);
            }
        }
        if (cost1<cost)
        {
            cost = cost1;
        }
    }
    cout << cost << endl;
}
