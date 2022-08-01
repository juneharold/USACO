#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll N, h[100005]={}, tree[400005]={};

ll query(ll n, ll a, ll b, ll qa, ll qb) { // return index of smallest height in qa~qb
    if (b<qa || qb<a) return 0;
    else if (qa<=a && b<=qb) return tree[n];
    ll mid=(a+b)/2;
    ll idx1=query(2*n, a, mid, qa, qb), idx2=query(2*n+1, mid+1, b, qa, qb);
    if (h[idx1]<h[idx2]) return idx1;
    else return idx2;
}

void update(ll n, ll a, ll b, ll qa, ll qb, ll v){
    if (b<qa || qb<a) return;
    else if (qa<=a && b<=qb) {tree[n]=v; return;}
    ll mid=(a+b)/2;

    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    if (h[tree[2*n]]<h[tree[2*n+1]]) tree[n]=tree[2*n];
    else tree[n]=tree[2*n+1];
}

ll solve(ll i, ll j) {
    if (i>j) return -1e18;
    ll idx=query(1, 1, N, i, j);
    ll ans=h[idx]*(j-i+1);
    ans=max(ans, solve(i, idx-1));
    ans=max(ans, solve(idx+1, j));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    h[0]=1e18;
    while (true) {
        cin >> N;
        if (N==0) exit(0);
        for (ll i=1; i<=N; i++) {
            cin >> h[i];
            update(1, 1, N, i, i, i);
        }
        cout << solve(1, N) << "\n";
        fill(&h[1], &h[N+1], 0);
        fill(&tree[0], &tree[4*N+1], 0);
    }
}
