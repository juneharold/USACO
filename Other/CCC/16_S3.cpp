#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=1e5+5;
int N, M, pho[MAX]={}, dp[MAX]={}, total_dist=0, visit[MAX]={};
vector<int> tree[MAX];

void dfs1(int cur, int p) {
    if (pho[cur]==1) dp[cur]++;

    for (auto nx: tree[cur]) {
        if (nx==p) continue;

        dfs1(nx, cur);
        if (dp[nx]!=0) {
            dp[cur]+=dp[nx];
            total_dist+=2;
        }
    }
}

void dfs2(int cur, int p) {
    visit[cur]=visit[p]+1;
    for (auto nx: tree[cur]) {
        if (nx==p) continue;
        dfs2(nx, cur);
        visit[nx]=visit[cur]+1;
    }
}

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a; cin >> a;
        pho[a]=1;
    }
    for (int i=0; i<N-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // find where to start
    dfs2(0, 100000);
    int dist=0, u=0;
    for (int i=0; i<N; i++) {
        if (visit[i]>dist && pho[i]==1) {
            u=i;
            dist=visit[i];
        }
        visit[i]=0;
    }

    // compute number of pho restaurants
    dfs1(u, 100000);

    // find longest path from u
    dfs2(u, 100000);
    int width=0;
    for (int i=0; i<N; i++) {
        if (visit[i]!=0 && pho[i]==1) width=max(width, visit[i]);
    }
    cout << total_dist-width+1;
}


/*
7 3
0 1 6
0 1
1 2
2 3
3 4
4 5
5 6


*/
