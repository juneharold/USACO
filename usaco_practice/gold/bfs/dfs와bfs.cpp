#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, v;
int visit[1005]={};
set<int> graph[1005];

void dfs (int cur) {
    visit[cur]=1;
    cout << cur << " ";
    for (auto it: graph[cur]) {
        if (visit[it]==0) dfs(it);
    }
}

int main()
{
    cin >> n >> m >> v;
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    dfs(v);
    cout << "\n";
    fill(&visit[0], &visit[1005], 0);
    queue <int> q;
    q.push(v);
    while (!q.empty()) {
        int cur=q.front();
        visit[cur]=1;
        cout << cur << " ";
        for (auto it: graph[cur]) {
            if (visit[it]==0) {
                q.push(it);
                visit[it]=1;
            }
        }
        q.pop();
    }
}
