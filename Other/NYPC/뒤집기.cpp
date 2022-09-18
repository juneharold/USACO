#include<iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll a[1000005]={}, dp1[1000005]={}, dp2[1000005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];

    for (int i=1; i<=N; i++) {
        dp1[i]=max(a[i], dp1[i-1]+a[i]);
    }

    ll ans=-1e18, mx=0;
    for (int i=N; i>=1; i--) {
        dp2[i]=max(a[i], dp2[i+1]+a[i]);
        ans=max(ans, mx+dp1[i]);
        mx=max(mx, dp2[i]);
    }
    cout << ans;
}
