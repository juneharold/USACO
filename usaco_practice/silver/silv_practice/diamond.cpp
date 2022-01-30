#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int N, K, arr[50005]={}, p[50005]={}, pmax[50005]={};

int main()
{
    //freopen("diamond.in", "r", stdin);
    //freopen("diamond.out", "w", stdout);
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> arr[i];
    sort(&arr[1], &arr[N+1]);

    fill(&p[1], &p[N+1], 1);

    for (int i=1; i<=N; i++) {
        int lo=i, hi=N;
        while (lo<hi) {
            int mid=(lo+hi)/2+1;
            if (abs(arr[i]-arr[mid])<=K) lo=mid;
            else hi=mid-1;
        }
        p[i]=lo-i+1;
    }

    int mx=0;
    for (int i=N; i>=1; i--) {
        mx=max(mx, p[i]);
        pmax[i]=mx;
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        ans=max(ans, p[i]+pmax[i+p[i]]);
    }
    cout << ans;
}

/*
7 3
10
5
1
12
9
5
14

2 2
1
1

8 2
1
3
3
3
4
4
4
6

12 2
1
3
3
3
5
5
10
12
12
12
14
14
*/
