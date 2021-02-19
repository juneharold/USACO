#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int hays[50005]={};

int main()
{
    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; cin >> N >> K;
    for (int i=0; i<N; i++) cin >> hays[i];
    sort(hays, hays+N);
    int low=0, high=1e9;
    while (low<high)
    {
        int mid=(low+high)/2;
        int from=hays[0], counter=1; 
        for (int i=1; i<N; i++)
        {
            if (hays[i]>from+mid+mid)
            {
                from=hays[i];
                counter++;
            }
        }
        if (counter<=K) high=mid;
        else low=mid+1;
    }
    cout << low;
}


/*
7 2
20
19
18
8
7
3
1

correct output: 4
*/
