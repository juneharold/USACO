#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> V_C[2000005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M, K;
    cin >> N >> M >> K;
    for (int i=0; i<K; i++) cin >> V_C[i].first >> V_C[i].second;
    sort(V_C, V_C+K);
    long long low=0, high=1e10;
    int maxdrank=0;
    while (low<high)
    {
        long long mid = (low+high)/2;
        long long sum=0, drank=0;
        for (int i=K-1; i>=0; i--)
        {
            if (drank==N) break;
            if (V_C[i].second<=mid)
            {
                sum+=V_C[i].first;
                drank++;
            }
        }
        if (sum<M or drank<N) low = mid+1;
        else 
        {
            high=mid;
            if (drank>maxdrank) maxdrank=drank;
        }
    }
    if (maxdrank<N)
    {
        cout << -1;
        return 0;
    }
    cout << low;
}


/*
3 9 5
3 5
3 5
3 1
3 3
3 4

2 100 2
49 10
50 100000


2 10 3
100 1
10 2
10 3
*/
