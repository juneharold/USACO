/*
dp[i]=maximum sum when last flower has height i 
dp[i]=a[i]+max(dp[i-1], dp[i-2], ..., dp[0]);
O(n^2)
use segment tree
find maximum and update in O(log n)
O(nlogn)
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll h[200005]={}, a[200005]={}, tree[800005]={};

void update(ll n, ll a, ll b, ll qa, ll qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) {tree[n]=max(tree[n], v); return;}
    ll mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    tree[n]=max(tree[2*n], tree[2*n+1]);
}

ll query(ll n, ll a, ll b, ll qa, ll qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return tree[n];
    ll mid=(a+b)/2;
    return max(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}

int main()
{
    ll N; cin >> N;
    for (ll i=1; i<=N; i++) cin >> h[i];
    for (ll i=1; i<=N; i++) cin >> a[i];
    
    ll ans=0;
    for (ll i=1; i<=N; i++) {
        ll temp;
        if (h[i]!=1) temp=query(1, 1, N, 1, h[i]-1)+a[i];
        else temp=a[i];
        ans=max(ans, temp);
        update(1, 1, N, h[i], h[i], temp);
    }
    cout << ans;
}
