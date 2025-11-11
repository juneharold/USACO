#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int query(int l, int r) {
    cout << "? " << l << ' ' << r << "\n";
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<int> mxr(n+5, -1);
    int l, r;
    for (int i=0; i<q; i++) {
        cin >> l >> r;
        mxr[l]=max(mxr[l], r);
    }

    vector<pii> ranges;
    l=-1, r=-1;
    for (int i=1; i<=n; i++) {
        if (l==-1 && mxr[i]!=-1) {
            l=i;
            r=mxr[i];
        }
        else if (l!=-1 && mxr[i]>r) {
            l=i;
            r=mxr[i];
        }
        if (l!=-1 && (ranges.empty() || ranges.back()!=make_pair(l, r))) ranges.push_back({l, r});
    }
    
    int ans=0, lo=0, hi=ranges.size()-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        l=ranges[mid].fs;
        r=ranges[mid].sc;
        int res1=query(1, r), res2=query(l, n);
        ans=max(ans, min(res1, res2));
        if (res1>res2) hi=mid-1;
        else lo=mid+1;
    }
    cout << "! " << ans << "\n";
    cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
