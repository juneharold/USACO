#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long

const ll mod=1e9+7;
ll a[300005]={}, pw[300005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N, ans=0; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    sort(&a[1], &a[N+1]);

    pw[0]=1;
    for (int i=1; i<=N; i++) {
        pw[i]=2*pw[i-1];
        pw[i]%=mod;
    }
    for (int i=1; i<=N; i++) {
        ans+=(pw[i-1]-pw[N-i])*a[i];
        ans%=mod;
    }
    cout << ans;
}

/*
2
1 3
3 1
2
*/
