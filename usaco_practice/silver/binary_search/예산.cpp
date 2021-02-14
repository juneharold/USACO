#include <iostream>
using namespace std;

int request[100005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N; 
    int sum=0, MAX=0;
    for (int i=0; i<N; i++) 
    {
        cin >> request[i];
        sum+=request[i];
        if (request[i]>MAX) MAX=request[i];
    }
    int budget; cin >> budget;
    if (sum<=budget) 
    {
        cout << MAX << "\n";
        return 0;
    }
    long long high=1000000000, low=0;
    while (low<high)
    {
        int mid=(low+high+1)/2;
        int give_out=0;
        for (int i=0; i<N; i++)
        {
            if (request[i]>=mid) give_out+=mid;
            else give_out+=request[i];
        }
        if (give_out>budget) high=mid-1;
        else low=mid;
    }
    cout << low << "\n";
    return 0;
}

/*
4
120 110 140 150
485

4
120 120 120 126
485
*/

