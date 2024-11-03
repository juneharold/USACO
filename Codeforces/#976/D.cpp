#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<pii> v[11][11];

int leader[nmax], sz[nmax];
int Find(int x) {
    if (leader[x]==x) return x;
    return leader[x]=Find(leader[x]);
}
void Union (int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    leader[a]=b;
    sz[b]+=sz[a];
}

void solve() {
    int n, m; cin >> n >> m;
    int a, d, k; 
    for (int i=1; i<=m; i++) {
        cin >> a >> d >> k;
        v[d][a%d].push_back({a, a+d*k});
    }

    for (int i=1; i<=n; i++) {
        leader[i]=i;
        sz[i]=1;
    }

    int ans=n;
    for (int d=1; d<=10; d++) {
        for (int x=0; x<d; x++) {
            sort(v[d][x].begin(), v[d][x].end());

            for (int i=0; i<v[d][x].size(); i++) {
                pii r=v[d][x][i];
                int cur=r.fs;
                if (i>0 && r.sc<=v[d][x][i-1].sc) continue;
                if (i>0 && r.fs<v[d][x][i-1].sc) cur=v[d][x][i-1].sc;
                while (cur+d<=r.sc) {
                    if (Find(cur)!=Find(cur+d)) {
                        ans--;
                        Union(cur, cur+d);
                    }
                    cur+=d;
                }
            }
        }
    }

    cout << ans << "\n";

    for (int d=1; d<=10; d++) {
        for (int x=0; x<d; x++) {
            v[d][x].clear();
        }
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
