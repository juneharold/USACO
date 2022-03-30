#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define ll long long
#define f first
#define s second

int N, M, visit[200005]={}, num_comp[200005]={};
vector<int> nopath[200005], next_node;
multiset<int> sizes;
set<int> unvisited;

void dfs(int cur, int code) {
    visit[cur]=code;
    unvisited.erase(cur);

    int idx=0;
    for (auto nx: unvisited) {
        while (idx<nopath[cur].size()-1 && nopath[cur][idx]<nx) {
            idx++;
        }

        if (nopath[cur][idx]!=nx) {
            visit[nx]=code;
            next_node.push_back(nx);
        }
    }

    for (auto x: next_node) unvisited.erase(x);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        nopath[a].push_back(b);
        nopath[b].push_back(a);
    }

    for (int i=1; i<=N; i++) unvisited.insert(i);

    for (int i=1; i<=N; i++) {
        if (visit[i]==0) {
            dfs(i, i);
        }
    }

    int cnt=0, sz=0;
    for (int i=1; i<=N; i++) {
        num_comp[visit[i]]++;
    }
    for (int i=1; i<=N; i++) {
        if (num_comp[i]!=0) {
            cnt++;
            sizes.insert(num_comp[i]);
        }
    }
    cout << cnt << "\n";
    for (int x: sizes) cout << x << " ";
}
