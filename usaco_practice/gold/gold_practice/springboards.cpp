#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int X1[nmax]={}, Y1[nmax]={}, X2[nmax]={}, Y2[nmax]={};

int segtree[8*nmax]={};
int query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return segtree[n];
    int mid=(a+b)/2;
    return min(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}
void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) { segtree[n]=v; return; }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    segtree[n]=min(segtree[2*n], segtree[2*n+1]);
}

void solve() {
    int N, P; cin >> N >> P;
    map<pii, int> comp;
    vector<pair<pii, pii>> v;
    for (int i=1; i<=P; i++) {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        v.push_back({{X1[i], Y1[i]}, {0, i}});
        v.push_back({{X2[i], Y2[i]}, {1, i}});
        comp[{Y1[i], X1[i]}]=1;
        comp[{Y2[i], X2[i]}]=1;
    }
    int num=0;
    for (auto &y: comp) y.sc=++num;

    vector<int> ans(P+1);
    sort(v.begin(), v.end());
    for (auto xx: v) {
        int type=xx.sc.fs, i=xx.sc.sc;
        if (type==0) ans[i]=X1[i]+Y1[i]+query(1, 1, num, 1, comp[{Y1[i], X1[i]}]);
        else update(1, 1, num, comp[{Y2[i], X2[i]}], comp[{Y2[i], X2[i]}], ans[i]-X2[i]-Y2[i]);
    }
    cout << 2*N+query(1, 1, num, 1, num);
}

int main()
{
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
