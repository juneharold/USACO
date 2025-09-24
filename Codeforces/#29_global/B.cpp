#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void check(vector<int> &ans, int n) {
    vector<vector<int>> pos(n+5, vector<int>());
    for (int i=1; i<=2*n; i++) pos[ans[i]].push_back(i);

    for (int i=1; i<=n; i++) {
        if (pos[i].size()!=2) {
            cout << "NO\n" << i << ' ' << pos[i].size() << endl;
            return;
        }
        if ((pos[i].back()-(*pos[i].begin()))%i!=0) {
            cout << "NO \n" << i << endl;
            return;
        }
    }
    cout << "YES\n";
}

void solve() {
    int n; cin >> n;
    if (n==1) {
        cout << "1 1\n";
        return;
    }
    vector<int> ans(5*n+5, 0);
    ans[n]=n;
    ans[2*n]=n;
    ans[2*n+1]=1;
    int mn=n, mx=2*n+1;
    int diff=1;
    for (int i=2; i<n; i+=2) {
        ans[n+diff]=i;
        ans[n-diff]=i;
        mn=min(mn, n-diff);
        diff++;
    }

    diff=1;
    for (int i=3; i<n; i+=2) {
        ans[2*n+diff+1]=i;
        ans[2*n-diff]=i;
        mx=max(mx, 2*n+diff+1);
        diff++;
    }

    vector<int> b(2*n+1, 0);
    int idx=1;
    for (int i=mn; i<=mx; i++) {
        if (ans[i]==0) ans[i]=1;
        cout << ans[i] << ' ';

        b[idx]=ans[i];
        idx++;
    }
    cout << "\n";

    //check(b, n);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
