#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define f first
#define s second
const int MAX_N=2e5+5;
int N, dp[MAX_N]={}, parent[MAX_N];
pair<int, int> child1[MAX_N], child2[MAX_N];
vector<int> graph[MAX_N];

pair<int, int> down(int cur, int p) {
    if (child1[cur].f!=-1 && child2[cur].f!=-1) return {child1[cur].f, child2[cur].f};

    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==p) continue;
        if (down(nx, cur).f+1>child1[cur].f) {
            child2[cur]={child1[cur].f, child1[cur].s};
            child1[cur]={down(nx, cur).f+1, nx};
        }
        else if (down(nx, cur).f+1>child2[cur].f) {
            child2[cur]={down(nx, cur).f+1, nx};
        }
    }
    child1[cur]=max(child1[cur], {0, 0});
    child2[cur]=max(child2[cur], {0, 0});
    return {child1[cur].f, child2[cur].f};
}

void up(int cur, int p) {
    parent[cur]=max(parent[cur], parent[p]+1);
    if (child1[p].s!=cur) parent[cur]=max(parent[cur], child1[p].f+1);
    if (child2[p].s!=cur) parent[cur]=max(parent[cur], child2[p].f+1);

    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (nx==p) continue;
        up(nx, cur);
    }
}

int main()
{
    cin >> N;
    for (int i=1; i<N; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill(&child1[0].f, &child1[MAX_N].f, -1);
    fill(&child2[0].f, &child2[MAX_N].f, -1);
    fill(&parent[0], &parent[MAX_N], -1);

    down(1, 0);
    up(1, 0);

    for (int i=1; i<=N; i++) {
        dp[i]=max(dp[i], parent[i]);
        dp[i]=max(dp[i], child1[i].f);
        dp[i]=max(dp[i], child2[i].f);
    }
    int ans=0;
    for (int i=1; i<=N; i++) {
        ans=max(ans, dp[i]);
    }
    cout << ans;
}
