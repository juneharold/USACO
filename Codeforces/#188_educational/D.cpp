#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<int> graph[nmax];

vector<int> component;
bool works=true;
int vst[nmax]={};
void dfs(int cur, int type) {
    vst[cur]=type;
    component.push_back(cur);
    for (int nx: graph[cur]) {
        if (vst[nx]==0) dfs(nx, 3-type); // 1 or 2
        else if (vst[nx]!=3-type) works=false;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        if (vst[i]==0) {
            int temp1=0;
            dfs(i, 1);
            if (works) {
                for (int x: component) {
                    if (vst[x]==1) temp1++;
                }
            }
            works=true;
            for (int x: component) vst[x]=0;
            component.clear();

            int temp2=0;
            dfs(i, 2);
            if (works) {
                for (int x: component) {
                    if (vst[x]==1) temp2++;
                }
            }
            works=true;
            component.clear();

            ans+=max(temp1, temp2);
        }
    }
    cout << ans << "\n";

    fill(&vst[0], &vst[n+1], 0);
    for (int i=1; i<=n; i++) graph[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
