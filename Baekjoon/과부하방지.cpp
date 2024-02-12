#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll N, K, M; cin >> N >> K >> M;
    vector<ll> A(N), D(M);
    for (ll i=0; i<N; i++) cin >> A[i];
    for (ll i=0; i<M; i++) cin >> D[i];
    sort(A.begin(), A.end());
    sort(D.begin(), D.end());

    ll lo=0, hi=M;
    while (lo<hi) {
        ll mid=(lo+hi)/2+1;
        vector<ll> d;
        for (ll i=M-1; i>=M-mid; i--) d.push_back(D[i]);

        bool possible=true;
        ll level=0, socket=K, idx=N-1;
        while (!d.empty()) {
            ll cnt=0;
            while (!d.empty() && d.back()==level) {
                cnt++;
                d.pop_back();
            }
            if (cnt>socket) {
                possible=false;
                break;
            }
            socket-=cnt;
            ll temp=socket;
            for (ll i=0; i<temp; i++) {
                if (idx<0) break;
                if (socket==0) possible=false;
                socket+=A[idx--]-1;
            }
            level++;
        }
        if (possible) lo=mid;
        else hi=mid-1;
    }
    cout << lo;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
