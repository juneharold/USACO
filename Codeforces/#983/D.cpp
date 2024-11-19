#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int query(int a, int b, map<pii, int> &ans) {
    if (ans.find(make_pair(a, b))!=ans.end()) {
        return ans[make_pair(a, b)];
    }
    cout << "? " << a << ' ' << b << "\n"; cout.flush();
    int ret; cin >> ret;
    if (ret==-1) {
        exit(0);
    }
    ans[make_pair(a, b)]=ret;
    ans[make_pair(b, a)]=ret;
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n, 0);
    map<pii, int> ans;
    int from;
    for (int i=2; i<n; i++) {
        int res=query(1, i, ans);
        if (res==1) {
            p[i]=0;
        }
        else {
            from=i;
            break;
        }
    }

    int mn=1;
    for (int i=from; i<n; i++) {
        int res=query(mn, i, ans);
        while (res==1) {
            mn++;
            res=query(mn, i, ans);
        }
        p[i]=mn;
        mn++;
    }

    cout << "! "; cout.flush();
    for (int i=1; i<n; i++) cout << p[i] << ' '; cout.flush();
    cout << "\n"; cout.flush();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
