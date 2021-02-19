#include <iostream>
#include <algorithm>
using namespace std;

int arrival[100005]={};

int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int N, M, C; cin >> N >> M >> C;
    for (int i=0; i<N; i++) cin >> arrival[i];
    sort(arrival, arrival+N);
    int low=0, high=1e9;
    while (low<high)
    {
        int mid=(low+high)/2;
        int time=arrival[0], on_board=1, counter=1;
        for (int i=1; i<N; i++)
        {
            if (arrival[i]>time+mid or on_board==C)
            {
                counter++;
                on_board=1;
                time=arrival[i];
            }
            else
            {
                on_board++;
            }
        }
        if (counter>M) low=mid+1;
        else high=mid;
    }
    cout << low;
}

/*
6 3 3
1 5 10 12 4 3
*/
