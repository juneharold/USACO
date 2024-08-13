#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n+1), b(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    ll idx=-1, mx=-INF;
    for (int i=1; i<=n; i++) {
        if (a[i]>mx && b[i]==1) idx=i, mx=a[i];
    }
    vector<int> v;
    for (int i=1; i<=n; i++) if (i!=idx) v.push_back(a[i]);
    sort(v.begin(), v.end());
    ll ans=mx+k+(v.size()>0 ? v[(v.size()-1)/2] : 0);

    idx=-1, mx=-INF;
    for (int i=1; i<=n; i++) {
        if (a[i]>mx && b[i]==0) idx=i, mx=a[i];
    }
    vector<pii> v2;
    for (int i=1; i<=n; i++) if (i!=idx) v2.push_back({a[i], b[i]});
    sort(v2.begin(), v2.end());
    ll lo=0, hi=2e9;
    while (lo<hi) {
        ll mid=(lo+hi+1)/2;
        ll need=(v2.size()+2)/2, cnt_operations=0;
        for (int i=v2.size()-1; i>=0; i--) {
            if (v2[i].fs>=mid) need--;
            else if (v2[i].fs<mid && v2[i].sc==1 && need>0) {
                cnt_operations+=mid-v2[i].fs;
                need--;
            }
        }
        if (cnt_operations>k || need>0) hi=mid-1;
        else lo=mid;
    }
    ans=max(ans, mx+lo);

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
