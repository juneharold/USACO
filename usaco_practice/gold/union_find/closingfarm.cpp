#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int N, M, p[200005]={}, sz[200005]={}, open[200005]={};
vector<int> graph[200005];

int Find(int x) {
    if (x==p[x]) return x;
    return p[x]=Find(p[x]);
}

void Union(int a, int b) {
    a=Find(a), b=Find(b);
    if(a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    p[a]=b;
    sz[b]+=sz[a];
}

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> order;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        order.push_back(x);
    }
    for (int i=1; i<=N; i++) {
        p[i]=i;
        sz[i]=1;
    }

    vector<string> ans;
    for (int i=N-1; i>=0; i--) {
        int cur=order[i];
        open[cur]=1;
        for (int j=0; j<graph[cur].size(); j++) {
            int nx=graph[cur][j];
            if (open[nx]==0) continue;
            Union(cur, nx);
        }
        if (sz[Find(cur)]==N-i) ans.push_back("YES");
        else ans.push_back("NO");
    }

    for (int i=N-1; i>=0; i--) cout << ans[i] << "\n";
}