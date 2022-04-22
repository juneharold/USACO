#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second
const ll MAX=1e6+5;

ll dp[MAX]={}, num[MAX]={}, from[MAX]={}, sz=1;
pair<ll, ll> A[MAX]={};
vector<ll> path;

ll binary_search(ll x) {
    ll lo=1, hi=sz;
    while (lo<hi) {
        ll mid=(lo+hi)/2+1;
        if (A[mid].f<x) lo=mid;
        else hi=mid-1;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll N; cin >> N;
    for (ll i=1; i<=N; i++) cin >> num[i];
    fill(&A[0], &A[MAX], make_pair(1e18, 1e18));

    ll cur=1;
    for (ll i=1; i<=N; i++) {
        if (num[i]<A[1].f) {
            dp[i]=1;
            A[1]={num[i], i};
        }

        ll res=binary_search(num[i]);
        if (A[res].f<num[i]) {
            from[i]=A[res].s;
            dp[i]=res+1;
            if (res+1>sz) {
                sz=res+1;
                cur=i;
            }
            if (num[i]<A[res+1].f) A[res+1]={num[i], i};
        }
    }

    while (cur!=0) {
        path.push_back(num[cur]);
        if (from[cur]==cur) break;
        cur=from[cur];
    }

    cout << sz << "\n";
    for (ll i=path.size()-1; i>=0; i--) cout << path[i] << " ";
}
