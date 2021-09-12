#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second

const int MAX_N=1e5+5;
int N, xl, yl, xb, yb, visit[MAX_N][5]={};
struct info {
    int id, x, y;
};
vector<info> vertex;
vector<pair<pair<int, int>, int>> graph[MAX_N][5];
priority_queue<pair<int, pair<int, int>>> pq;

bool cmpx (info a, info b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmpy (info a, info b) {
    if (a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

void make_graph() {
    sort(vertex.begin(), vertex.end(), cmpx);
    for (int i=0; i<=N+1; i++) {
        if (i>=1 && vertex[i-1].x==vertex[i].x) {
            graph[vertex[i].id][1].push_back({{vertex[i-1].id, 2}, 1});
            graph[vertex[i].id][2].push_back({{vertex[i-1].id, 2}, 0});
            graph[vertex[i].id][3].push_back({{vertex[i-1].id, 2}, 1});
            graph[vertex[i].id][4].push_back({{vertex[i-1].id, 2}, 1});
        }
        if (i<=N && vertex[i+1].x==vertex[i].x) {
            graph[vertex[i].id][1].push_back({{vertex[i+1].id, 1}, 0});
            graph[vertex[i].id][2].push_back({{vertex[i+1].id, 1}, 1});
            graph[vertex[i].id][3].push_back({{vertex[i+1].id, 1}, 1});
            graph[vertex[i].id][4].push_back({{vertex[i+1].id, 1}, 1});
        }
    }

    sort(vertex.begin(), vertex.end(), cmpy);
    for (int i=0; i<=N+1; i++) {
        if (i>=1 && vertex[i-1].y==vertex[i].y) {
            graph[vertex[i].id][1].push_back({{vertex[i-1].id, 4}, 1});
            graph[vertex[i].id][2].push_back({{vertex[i-1].id, 4}, 1});
            graph[vertex[i].id][3].push_back({{vertex[i-1].id, 4}, 1});
            graph[vertex[i].id][4].push_back({{vertex[i-1].id, 4}, 0});
        }
        if (i<=N && vertex[i+1].y==vertex[i].y) {
            graph[vertex[i].id][1].push_back({{vertex[i+1].id, 3}, 1});
            graph[vertex[i].id][2].push_back({{vertex[i+1].id, 3}, 1});
            graph[vertex[i].id][3].push_back({{vertex[i+1].id, 3}, 0});
            graph[vertex[i].id][4].push_back({{vertex[i+1].id, 3}, 1});
        }
    }
}

int main()
{
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> xl >> yl >> xb >> yb;
    vertex.push_back({N, xl, yl});
    vertex.push_back({N+1, xb, yb});
    for (int i=0; i<N; i++) {
        info a; cin >> a.x >> a.y;
        a.id=i;
        vertex.push_back(a);
    }

    make_graph();
    fill(&visit[0][0], &visit[MAX_N-1][5], 1e9);

    pq.push({0, {N, 1}}); visit[N][1]=0;
    pq.push({0, {N, 2}}); visit[N][2]=0;
    pq.push({0, {N, 3}}); visit[N][3]=0;
    pq.push({0, {N, 4}}); visit[N][4]=0;

    while (!pq.empty()) {
        int cost=-pq.top().f, cur=pq.top().s.f, dir=pq.top().s.s;
        pq.pop();

        if (cost>visit[cur][dir]) continue;

        for (auto nx: graph[cur][dir]) {
            if (cost+nx.s<visit[nx.f.f][nx.f.s]) {
                visit[nx.f.f][nx.f.s]=cost+nx.s;
                pq.push({-(cost+nx.s), {nx.f.f, nx.f.s}});
            }
        }
    }

    int ans=1e9;
    for (int i=1; i<=4; i++) ans=min(ans, visit[N+1][i]);
    if (ans==1e9) cout << -1;
    else cout << ans;
}
