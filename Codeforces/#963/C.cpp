#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];

    vector<ll> cnt(2*k+10, 0);
    for (int i=1; i<=n; i++) cnt[a[i]%(2*k)]++;

    bool possible=false;
    ll sum=0, l=0, r=k-1, last;
    set<int> active;
    for (int i=0; i<=k-1; i++) {
        sum+=cnt[i];
        if (cnt[i]>0) last=i;
    }
    for (int i=k; i<=4*k; i++) {
        //cout << l << ' ' << r << ' ' << sum << endl;
        if (sum==n) {
            possible=true;
            break;
        }
        r++;
        sum+=cnt[r%(2*k)]-cnt[l%(2*k)];
        if (cnt[r%(2*k)]>0) last=r%(2*k);
        l++;
    }
    if (!possible) {
        cout << "-1\n";
        return;
    }
    //cout << last << endl;

    ll ans=0;
    for (int i=1; i<=n; i++) ans=max(ans, (a[i]/(2*k))*(2*k));
    ans+=last;
    for (int i=1; i<=n; i++) if (ans<a[i]) ans+=2*k;
    cout << ans <<"\n";
}
/*
5 5
1 1 1 1 1 
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
