#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int n, res;

void make_query(int x, int k, vector<int> &s) {
    cout << "? " << x << ' ' << k << ' ';
    for (int ss: s) cout << ss << ' ';
    cout << "\n";
    cout.flush();
    cin >> res;
}

int val[505];
vector<int> nodes_with_val[505];

void solve() {
    cin >> n;
    vector<int> s;
    for (int i=1; i<=n; i++) s.push_back(i);

    int mx=0, start=-1;
    for (int i=1; i<=n; i++) {
        make_query(i, n, s);
        val[i]=res;
        nodes_with_val[res].push_back(i);
        if (res>mx) {
            mx=res;
            start=i;
        }
    }

    int cur=start;
    vector<int> ans;
    while (true) {
        ans.push_back(cur);
        if (val[cur]==1) break;
        int nx=-1, nv=val[cur]-1;
        for (int node: nodes_with_val[nv]) {
            vector<int> temp={cur, node};
            make_query(cur, 2, temp);
            if (res==2) {
                nx=node;
                break;
            }
        }
        cur=nx;
    }

    cout << "! " << ans.size() << ' ';
    for (int x: ans) cout << x << ' ';
    cout << "\n";
    cout.flush();

    for (int i=1; i<=n; i++) {
        val[i]=0;
        nodes_with_val[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
