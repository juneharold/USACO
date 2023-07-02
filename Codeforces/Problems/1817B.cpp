#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int n, m, vst[2005]={};
bool possible=false;
vector<int> graph[2005], path, cycle;

void dfs(int cur) {
    vst[cur]=1;
    path.push_back(cur);
    for (int nx: graph[cur]) {
        if (vst[nx]) {
            int idx=-1, mx=0;
            for (int i=0; i<path.size(); i++) {
                if (path[i]==nx) idx=i;
                if (idx!=-1) mx=max(mx, (int)graph[path[i]].size());
            }
            if (idx!=-1 && path.size()-idx>=3 && mx>=4) {
                possible=true;
                vector<int> temp;
                for (int i=idx; i<path.size(); i++) temp.push_back(path[i]);
                if (cycle.empty() || temp.size()<cycle.size()) cycle=temp;
            }
        }
        else dfs(nx);
    }
    path.erase(--path.end());
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i=1; i<=n; i++) {
        if (!vst[i] && !possible) dfs(i);
        path.clear();
    }

    vector<pair<int, int>> ans;
    if (!cycle.empty()) {
        vector<int> nodes(n+1, 0);
        for (int x: cycle) nodes[x]=1;
        bool tail=false;
        for (int i=0; i<cycle.size(); i++) {
            int x=cycle[i], y=cycle[(i+1)%cycle.size()];
            if (!tail && graph[x].size()>=4) {
                int cnt=0;
                for (int adj: graph[x]) {
                    if (nodes[adj]==0 && cnt<2) {
                        ans.push_back({x, adj});
                        cnt++;
                    }
                }
                tail=true;
            }
            ans.push_back({x, y});
        }
    }

    if (possible) {
        cout << "YES\n" << ans.size() << "\n";
        for (auto x: ans) cout << x.f << ' ' << x.s << "\n";
    }
    else cout << "NO\n";

    for (int i=1; i<=n; i++) {
        graph[i].clear();
        vst[i]=0;
    }
    path.clear();
    cycle.clear();
    possible=false;
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
/*
1
7 8
1 2
2 3
3 4
4 1
4 5
4 6
4 2
6 7
*/