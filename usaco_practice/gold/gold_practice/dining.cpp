#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
#define f first
#define s second

const int MAX=1e5+5;
int N, M, K, dist1[MAX], dist2[MAX], hay[MAX];
vector<pair<int, int>> graph1[MAX], graph2[MAX];
struct INPUT {
    int a, b, w;
};
INPUT input[MAX];
priority_queue<pair<int, int>> pq;
set<int> haybales;

int main()
{
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    cin >> N >> M >> K;
    fill(&dist1[0], &dist1[N+1], 1e9);
    fill(&dist2[0], &dist2[N+1], 1e9);

    for (int i=0; i<M; i++) {
        cin >> input[i].a >> input[i].b >> input[i].w;
        graph1[input[i].a].push_back({input[i].b, input[i].w});
        graph1[input[i].b].push_back({input[i].a, input[i].w});
    }
    for (int i=0; i<K; i++) {
        int p, q; cin >> p >> q;
        hay[p]+=q;
        haybales.insert(p);
    }

    pq.push({0, N}); dist1[N]=0;
    while (!pq.empty()) {
        int cur=pq.top().s, d=-pq.top().f;
        pq.pop();
        for (int i=0; i<graph1[cur].size(); i++) {
            int nx=graph1[cur][i].f, w=graph1[cur][i].s;
            if (d+w<dist1[nx]) {
                pq.push({-(d+w), nx});
                dist1[nx]=d+w;
            }
        }
    }
    for (auto i: haybales) {
        int w=dist1[i]-hay[i];
        //pq.push({-w, i}); dist2[i]=w;
        graph2[i].push_back({N, w});
        graph2[N].push_back({i, w});
    }
    for (int i=0; i<M; i++) {
        if (input[i].a==N || input[i].b==N) continue;
        graph2[input[i].a].push_back({input[i].b, min(input[i].w, dist1[input[i].a]+dist1[input[i].b])});
        graph2[input[i].b].push_back({input[i].a, min(input[i].w, dist1[input[i].a]+dist1[input[i].b])});
    }

    pq.push({0, N}); dist2[N]=0;
    while (!pq.empty()) {
        int cur=pq.top().s, d=-pq.top().f;
        pq.pop();
        for (int i=0; i<graph2[cur].size(); i++) {
            int nx=graph2[cur][i].f, w=graph2[cur][i].s;
            if (nx==N) continue;
            if (d+w<dist2[nx]) {
                pq.push({-(d+w), nx});
                dist2[nx]=d+w;
            }
        }
    }

    for (int i=1; i<N; i++) {
        if (dist2[i]<=dist1[i]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

}
