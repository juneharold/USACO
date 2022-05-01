#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int parent[10005]={}, visit[10005]={};

void dfs1(int cur) {
    visit[cur]=1;
    if (parent[cur]==0) return;
    dfs1(parent[cur]);
}

int dfs2(int cur) {
    if (visit[cur]==1) return cur;
    else return dfs2(parent[cur]);
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        for (int i=1; i<N; i++) {
            int a, b; cin >> a >> b;
            parent[b]=a;
        }

        int a, b; cin >> a >> b;
        dfs1(a);
        cout << dfs2(b) << "\n";
        fill(&parent[0], &parent[N+1], 0);
        fill(&visit[0], &visit[N+1], 0);
    }
}
