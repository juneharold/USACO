#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N=40005;
int B, E, P, N, M, visit[MAX_N][3]={};
vector<int> graph[MAX_N];
queue<int> q;

void bfs (int who, int start, int weight) {
    q.push(start); visit[start][who]=1;
    while(!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i];
            if (visit[nx][who]==0) {
                q.push(nx);
                visit[nx][who]=visit[cur][who]+weight;
            }
        }
    }
}

int main()
{
    cin >> B >> E >> P >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs(0, 1, B);
    bfs(1, 2, E);
    bfs(2, N, P);

    int ans=1e9;
    for (int i=1; i<=N; i++) {
        ans=min(ans, visit[i][0]+visit[i][1]+visit[i][2]);
    }
    cout << ans-3;
}
