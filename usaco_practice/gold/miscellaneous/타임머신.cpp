#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first 
#define s second 
#define ll long long

ll N, M, dist[505], edges[3][6005]={};

void bellman_ford() {
    for (ll i=1; i<=N-1; i++) {
        for (ll j=1; j<=M; j++) {
            int u=edges[0][j], v=edges[1][j], w=edges[2][j];
            if (dist[u]==1e18) continue;
            if (dist[u]+w<dist[v]) dist[v]=dist[u]+w;
        }
    }
}

int main()
{
    cin >> N >> M;
    for (ll i=1; i<=M; i++) cin >> edges[0][i] >> edges[1][i] >> edges[2][i];

    fill(&dist[0], &dist[501], 1e18);
    dist[1]=0;
    bellman_ford();
    for (ll i=1; i<=M; i++) {
        int u=edges[0][i], v=edges[1][i], w=edges[2][i];
            if (dist[u]==1e18) continue;
            if (dist[u]+w<dist[v]) {
                cout << -1;
                return 0;
            }
    }

    for (ll i=2; i<=N; i++) {
        if (dist[i]==1e18) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}