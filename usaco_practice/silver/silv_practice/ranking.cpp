#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

int N, M, visit[1005]={};
vector<int> graph1[1005], graph2[1005];

void dfs1(int cur) {
    visit[cur]=1;
    for (auto nx: graph1[cur]) {
        if (visit[nx]==0) dfs1(nx);
    }
}

void dfs2(int cur) {
    visit[cur]=1;
    for (auto nx: graph2[cur]) {
        if (visit[nx]==0) dfs2(nx);
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        dfs1(i);
        dfs2(i);

        for (int j=1; j<=N; j++) {
            if (visit[j]==0) ans++;
        }
        fill(&visit[1], &visit[N+1], 0);
    }

    cout << ans/2;
}
