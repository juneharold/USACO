#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long

const int MAX=2e5+5;
ll N, S, height[MAX]={}, visit[MAX]={}, ans=1e18;
vector<pair<ll, ll>> graph[MAX];
pair<ll, ll> nodes[MAX];
priority_queue<pair<ll, ll>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;
    for (int i=1; i<=N; i++) {
        int y, h; cin >> y >> h;
        graph[i].push_back({i+N, h});
        height[i]=y; height[i+N]=y+h;
        nodes[i]={y, i}; nodes[i+N]={y+h, i+N};
    }

    sort(&nodes[1], &nodes[2*N+1]);
    for (int i=2*N; i>=2; i--) {
        graph[nodes[i].s].push_back({nodes[i-1].s, abs(nodes[i].f-nodes[i-1].f)});
    }

    fill(&visit[0], &visit[2*N+1], 1e18);
    for (int i=1; i<=2*N; i++) {
        if (nodes[i].f==0) {
            pq.push({0, nodes[i].s});
            visit[nodes[i].s]=0;
        }
    }

    while (!pq.empty()) {
        ll cur=pq.top().s, d=-pq.top().f;
        pq.pop();
        for (int i=0; i<graph[cur].size(); i++) {
            ll nx=graph[cur][i].f, nd=graph[cur][i].s;
            if (cur+N==nx && height[nx]>=S) {
                ans=min(ans, d+abs(S-height[cur]));
                continue;
            }
            if (d+nd<visit[nx]) {
                visit[nx]=d+nd;
                pq.push({-(d+nd), nx});
            }
        }
    }

    if (ans==1e18) cout << "Ducks can't fly";
    else cout << ans;
}
