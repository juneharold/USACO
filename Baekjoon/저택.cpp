#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=2e5+5;
ll M, N, K, visit[MAX][2];
struct vertex{
    ll x, y, id;
};
vertex node[MAX];

bool cmp1 (vertex a, vertex b) {
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmp2 (vertex a, vertex b) {
    if (a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}

ll dist(vertex a, vertex b) {
    return abs(a.x-b.x)+abs(a.y-b.y);
}

vector<pair<ll, ll>> graph[MAX][2];
priority_queue<pair<ll, pair<ll, ll>>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> K;
    for (ll i=1; i<=K; i++) {
        cin >> node[i].x >> node[i].y;
        node[i].id=i;
    }
    node[0]={1, 1, 0};
    node[K+1]={M, N, K+1};

    sort(&node[0], &node[K+2], cmp1);
    for (ll i=0; i<=K+1; i++) {
        if (i!=0 && node[i-1].x==node[i].x) {
            graph[node[i].id][0].push_back({node[i-1].id, dist(node[i-1], node[i])});
        }
        if (i!=K+1 && node[i].x==node[i+1].x) {
            graph[node[i].id][0].push_back({node[i+1].id, dist(node[i+1], node[i])});
        }
    }

    sort(&node[0], &node[K+2], cmp2);
    for (ll i=0; i<=K+1; i++) {
        if (i!=0 && node[i-1].y==node[i].y) {
            graph[node[i].id][1].push_back({node[i-1].id, dist(node[i-1], node[i])});
        }
        if (i!=K+1 && node[i].y==node[i+1].y) {
            graph[node[i].id][1].push_back({node[i+1].id, dist(node[i+1], node[i])});
        }
    }

    fill(&visit[0][0], &visit[K+2][1], 1e18);
    pq.push({0, {0, 0}});
    visit[0][0]=0;
    while(!pq.empty()) {
        ll cur=pq.top().s.f, state=pq.top().s.s, w=-pq.top().f;
        pq.pop();

        for (ll i=0; i<graph[cur][state].size(); i++) {
            ll nx=graph[cur][state][i].f, nw=graph[cur][state][i].s;
            if (w+nw<visit[nx][state]) {
                visit[nx][state]=w+nw;
                pq.push({-(w+nw), {nx, state}});
            }
        }

        if (cur!=0 && cur!=K+1) {
            if (w+1<visit[cur][1-state]) {
                visit[cur][1-state]=w+1;
                pq.push({-(w+1), {cur, 1-state}});
            }
        }
    }

    ll ans=min(visit[K+1][0], visit[K+1][1]);
    if (ans==1e18) cout << -1;
    else cout << ans;
}
