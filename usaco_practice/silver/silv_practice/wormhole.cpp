#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second
const int MAX=1e5+5;

int N, M, pos[MAX]={}, need[MAX]={}, visit[MAX]={};
vector<pair<int, int>> graph[MAX];

void dfs(int cur, int minW) {
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f, w=graph[cur][i].s;
        if (w<minW) continue;
        if (visit[nx]==0) dfs(nx, minW);
    }
}

int main()
{
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int start=1e9;
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> pos[i];
        if (pos[i]!=i) {
            need[i]=1; //i번째 location 연결 필요
            start=min(start, i);
        }
    }
    for (int i=1; i<=M; i++) {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    if (start==1e9) {
        cout << -1;
        exit(0);
    }

    int lo=1, hi=1e9+1;
    while (lo<hi) {
        int mid=(lo+hi)/2;

        dfs(start, mid);

        bool possible=true;
        for (int i=1; i<=N; i++) {
            if (need[i]==1 && visit[i]==0) possible=false;
            visit[i]=0;
        }

        if (possible) {
            lo=mid+1;
        }
        else {
            hi=mid;
        }
    }
    cout << lo-1;
}

/*
4 3
4 2 1 3
1 2 1
3 4 2
1 3 100
*/
