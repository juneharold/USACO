#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> V_C[200005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M, K;
    cin >> N >> M >> K;
    for (int i=0; i<K; i++) cin >> V_C[i].first >> V_C[i].second;
    sort(V_C, V_C+K);
    long long low=0, high=1e10;
    long long drank=0, sum=0;
    for (int i=K-1; i>=0; i--)
    {
        if (drank==N) break;
        sum+=V_C[i].first;
        drank++;
    }
    if (sum<M)
    {
        cout << -1;
        return 0;
    }
    while (low<high)
    {
        long long mid = (low+high)/2;
        long long sum=0, drank=0;
        for (int i=K-1; i>=0; i--)
        {
            if (drank==N) break;
            if (V_C[i].second>mid) continue;
            else
            {
                sum+=V_C[i].first;
                drank++;
            }
        }
        if (sum>=M) high=mid;
        else low=mid+1;
    }
    cout << low;
}

/*
3 9 5
2 5
4 6
3 3
4 3
1 4

1 100 2
99 10
99 10
*/
