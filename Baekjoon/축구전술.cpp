#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
using namespace std;

vector<int> graph[100005];
int vst[100005]={}, group[100005]={}, idx=0;
stack<int> s;

int dfs(int cur) {
    vst[cur]=++idx;
    s.push(cur);
    int parent=idx;
    for (int nx: graph[cur]) {
        if (vst[nx]==0) parent=min(parent, dfs(nx));
        else if (group[nx]==0) parent=min(parent, vst[nx]);
    }
    if (parent==vst[cur]) {
        while (!s.empty()) {
            if (s.top()==cur) {
                group[cur]=parent;
                s.pop();
                break;
            }
            group[s.top()]=parent;
            s.pop();
        }
    }
    return parent;
}

void solve() {
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
    }
    idx=0;
    for (int i=0; i<N; i++) {
        if (vst[i]==0) dfs(i);
    }

    vector<int> in(N+1, -1);
    set<int> unique; 
    for (int i=0; i<N; i++) {
        in[group[i]]=0;
        unique.insert(group[i]);
    }
    for (int i=0; i<N; i++) {
        for (int nx: graph[i]) {
            if (group[i]!=group[nx]) in[group[nx]]++;
        }
    }
    int cnt=0;
    for (int x: unique) {
        if (in[x]==0) cnt++;
    }

    if (cnt==1) {
        for (int i=0; i<N; i++) if (in[group[i]]==0) cout << i << "\n";
        cout << "\n";
    }
    else {
        cout << "Confused\n\n";
    }

    for (int i=0; i<N; i++) {
        graph[i].clear();
        vst[i]=0;
        group[i]=0;
    }
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}