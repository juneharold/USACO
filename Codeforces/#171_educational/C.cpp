#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll ans=n*(n+1)/2;
    priority_queue<ll> pq;
    for (ll i=n-1; i>=0; i--) {
        if (s[i]=='1') pq.push(i+1);
        else {
            if (!pq.empty()) {
                ans-=pq.top();
                pq.pop();
            }
        }
    }
    int m=pq.size();
    for (int i=0; i<m/2; i++) {
        ans-=pq.top(); 
        pq.pop();
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
