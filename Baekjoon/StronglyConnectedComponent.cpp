#include <iostream>
#include <algorithm>
#include <vector> 
#include <stack>
using namespace std;

int vst[10005]={}, grouped[10005]={}, idx=1;
vector<int> graph[10005];
stack<int> s;
vector<vector<int>> ans;

int dfs(int cur) {
    vst[cur]=idx++;
    s.push(cur);
    int parent=vst[cur];
    for (int nx: graph[cur]) {
        if (vst[nx]==0) parent=min(parent, dfs(nx));
        else if (grouped[nx]==0) parent=min(parent, vst[nx]);
    }
    vector<int> scc;
    if (parent==vst[cur]) {
        while (!s.empty()) {
            if (s.top()==cur) {
                grouped[cur]=1;
                scc.push_back(cur);
                s.pop();
                break;
            }
            grouped[s.top()]=1;
            scc.push_back(s.top());
            s.pop();
        }
        sort(scc.begin(), scc.end());
        if (scc.size()>0) ans.push_back(scc);
    }
    return parent;
}

int main()
{
    int V, E; cin >> V >> E;
    for (int i=0; i<E; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i=1; i<=V; i++) {
        if (vst[i]==0) dfs(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto scc: ans) {
        for (int x: scc) cout << x << ' ';
        cout << "-1\n";
    }
}
