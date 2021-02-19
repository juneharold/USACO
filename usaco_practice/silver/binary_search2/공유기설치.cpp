#include <iostream>
#include <algorithm>
using namespace std;

int houses[200005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, C; cin >> N >> C;
    for (int i=0; i<N; i++) cin >> houses[i];
    sort(houses, houses+N);
    int low=1, high=1e9;
    while(low<high)
    {
        int mid=(low+high)/2+1;
        int at=houses[0], counter=1;
        for (int i=1; i<N; i++)
        {
            if (at+mid<=houses[i])
            {
                at=houses[i];
                counter++;
            }
        }
        if (counter>=C) low=mid;
        else high=mid-1;
    }
    cout << low;
}

/*
5 3
1
2
3
4
6
*/