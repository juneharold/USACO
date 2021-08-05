#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define f first
#define s second
#define ll long long

const ll MAX=1005;
ll A, B, N;
pair<ll, ll> graph[MAX][MAX];
ll min_flight[MAX]={}, min_cost[MAX]={};
priority_queue<pair<ll, pair<ll, ll>>> pq;

int main()
{
    //freopen("cowroute.in", "r", stdin);
    //freopen("cowroute.out", "w", stdout);
    fill(&graph[0][0].f, &graph[MAX-1][MAX-1].f, 1e18);
    fill(&graph[0][0].s, &graph[MAX-1][MAX-1].s, 1e18);
    //input
    cin >> A >> B >> N;
    for (ll i=0; i<N; i++) {
        ll cost, nc, cities[MAX]; cin >> cost >> nc;
        for (ll j=0; j<nc; j++) cin >> cities[j];

        for (ll j=0; j<nc; j++) {
            for (ll k=0; k<j; k++) {
                graph[cities[k]][cities[j]]=min(graph[cities[k]][cities[j]], make_pair(cost, j-k));
            }
        }
    }

    // dijkstra, find min_cost;
    fill(&min_cost[0], &min_cost[MAX], 1e18);
    fill(&min_flight[0], &min_flight[MAX], 1e18);
    pq.push({0, {A, 0}}); min_cost[A]=0; min_flight[A]=0;

    while (!pq.empty()) {
        ll cost=-pq.top().f, cur=pq.top().s.f, dist=pq.top().s.s;
        pq.pop();
        if (cost>min_cost[cur]) continue;

        for (ll i=1; i<MAX; i++) {
            ll nx=i, n_cost=graph[cur][i].f, nd=graph[cur][i].s;
            if (n_cost==1e18) continue;

            if (cost+n_cost<min_cost[nx]) {
                min_cost[nx]=cost+n_cost;
                min_flight[nx]=dist+nd;
                pq.push({-(cost+n_cost), {nx, dist+nd}});
            }
            else if (cost+n_cost==min_cost[nx] && dist+nd<min_flight[nx]) {
                min_cost[nx]=cost+n_cost;
                min_flight[nx]=dist+nd;
                pq.push({-(cost+n_cost), {nx, dist+nd}});
            }
        }
    }

    if (min_cost[B]==1e18)  cout << "-1 -1";
    else cout << min_cost[B] << " " << min_flight[B];
}

/*
1 5 2
3 3
1 5 4
3 5
1 2 3 4 5
*/
