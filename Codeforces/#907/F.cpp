#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

ll segtree[4*nmax]={};
ll query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return query(2*n, a, mid, qa, qb)+query(2*n+1, mid+1, b, qa, qb);
}
void update(int n, int a, int b, int qa, int qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=segtree[2*n]+segtree[2*n+1];
}

int q, added_time[nmax]={};
vector<int> graph[nmax];
vector<pii> queries[nmax];
ll ans[nmax]={};

void dfs(int cur) {
    for (auto pr: queries[cur]) {
        update(1, 1, q, pr.fs, pr.fs, pr.sc);
    }
    ans[cur]=query(1, 1, q, added_time[cur], q);

    for (int nx: graph[cur]) {
        dfs(nx);
    }

    for (auto pr: queries[cur]) {
        update(1, 1, q, pr.fs, pr.fs, 0);
    }
}

void solve() {
    cin >> q;
    int sz=1;
    for (int i=1; i<=q; i++) {
        int type, v, x; cin >> type;
        if (type==1) {
            cin >> v;
            added_time[sz+1]=i;
            graph[v].push_back(sz+1);
            sz++;
        }
        else {
            cin >> v >> x;
            queries[v].push_back({i, x});
        }
    }

    dfs(1);

    for (int i=1; i<=sz; i++) cout << ans[i] << ' ';
    cout << "\n";

    for (int i=1; i<=sz; i++) {
        graph[i].clear();
        queries[i].clear();
        ans[i]=0;
        added_time[i]=0;
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
