#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

priority_queue<int> dist[1005];
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edge[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    for (int i=0; i<M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b, c});
    }

    pq.push({0, 1});
    dist[1].push(0);

    while (!pq.empty()) {
        int weight=-pq.top().first, cur=pq.top().second;
        pq.pop();

        for (int i=0; i<edge[cur].size(); i++) {
            int nx=edge[cur][i].first, nw=edge[cur][i].second;
            if (dist[nx].size()<K) {
                dist[nx].push(weight+nw);
                pq.push({-(weight+nw), nx});
            }
            else if (dist[nx].top()>weight+nw) {
                dist[nx].pop();
                dist[nx].push(weight+nw);
                pq.push({-(weight+nw), nx});
            }
        }
    }

    for (int i=1; i<=N; i++) {
        if (dist[i].size()<K) cout << "-1\n";
        else cout << dist[i].top() << "\n";
    }
}

/*
5 10 1
1 2 2
1 3 7
1 4 5
1 5 6
2 4 2
2 3 4
3 4 6
3 5 8
5 2 4
5 4 1
*/
