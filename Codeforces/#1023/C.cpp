#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll max_subarray(vector<ll> v) {
    ll sum=0, mn=0, ret=-INF;
    for (ll i=0; i<v.size(); i++) {
        sum+=v[i];
        ret=max(ret, sum-mn);
        mn=min(mn, sum);
    }
    return ret;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<char> s(n+2);
    for (ll i=1; i<=n; i++) cin >> s[i];
    vector<ll> a(n+2);
    for (ll i=1; i<=n; i++) cin >> a[i];

    a[0]=0;
    s[0]='1';
    a[n+1]=0;
    s[n+1]='1';
    n=n+1;


    ll cnt0=0;
    for (ll i=0; i<=n; i++) {
        if (s[i]=='0') cnt0++;
    }

    vector<pii> groups;
    for (ll i=0; i<=n; i++) {
        if (s[i]=='0') continue;
        ll idx=i;
        while (idx<=n && s[idx]=='1') {
            idx++;
        }
        groups.push_back({i, idx-1});
        i=idx-1;
    }

    for (auto p: groups) {
        vector<ll> v=vector<ll>(&a[p.fs], &a[p.sc+1]);
        ll mxs=max_subarray(v);
        if (mxs>k) {
            cout << "No\n";
            return;
        }
        if (groups.size()==1 && cnt0==0) {
            if (mxs!=k) cout << "No\n";
            else {
                cout << "Yes\n";
                for (ll i=1; i<=n-1; i++) cout << a[i] << ' ';
                cout << "\n";
            }
            return;
        }
    }

    ll mx1=0, sum1=0, mx2=0, sum2=0;
    for (ll i=groups[0].sc; i>=groups[0].fs; i--) {
        sum1+=a[i];
        mx1=max(mx1, sum1);
    }
    for (ll i=groups[1].fs; i<=groups[1].sc; i++) {
        sum2+=a[i];
        mx2=max(mx2, sum2);
    }
    ll target=k-mx1-mx2;
    a[groups[0].sc+1]=target;
    s[groups[0].sc+1]='1';
    for (ll i=groups[0].sc+2; i<=groups[1].fs-1; i++) {
        a[i]=0;
        s[i]='1';
    }
    for (ll i=0; i<=n; i++) {
        if (s[i]=='0') a[i]=-INF;
    }

    cout << "Yes\n";
    for (ll i=1; i<=n-1; i++) cout << a[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; cin >> T;
    while (T--) {
        solve();
    }
}
