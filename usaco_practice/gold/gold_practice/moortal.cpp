#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

const long long MAX=1e5+5;
long long N, M, K, cost[30][30]={}, pfs_cost[MAX][30]={}, dp[MAX][30]={}, min_dp[MAX]={};
string seq;
vector<pair<long long, long long>> adj[30];
priority_queue<pair<long long, long long>> pq;

void dijkstra() {
    for (long long j=1; j<=M; j++) {
        pq.push({0, j}); cost[j][j]=0;

        while (!pq.empty()) {
            long long weight=-pq.top().first, cur=pq.top().second;

            pq.pop();
            if (weight>cost[j][cur]) continue;
            for (long long i=0; i<adj[cur].size(); i++) {
                long long next=adj[cur][i].first, nw=adj[cur][i].second;
                if (weight+nw<cost[j][next]) {
                    cost[j][next]=weight+nw;
                    pq.push({-(weight+nw), next});
                }
            }
        }
    }
}

void find_cost() {
    for (long long i=1; i<=N; i++) {
        for (long long j=1; j<=M; j++) {
            long long let=seq[i-1]-96;
            pfs_cost[i][j]=pfs_cost[i-1][j]+cost[let][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen("cowmbat.in", "r", stdin);
    //freopen("cowmbat.out", "w", stdout);

    cin >> N >> M >> K >> seq;
    for (long long i=1; i<=M; i++) for (long long j=1; j<=M; j++) {
        long long a; cin >> a;
        adj[i].push_back({j, a});
    }

    fill(&cost[0][0], &cost[29][30], 1e9);
    fill(&dp[1][0], &dp[MAX-1][30], 1e9);
    fill(&min_dp[1], &min_dp[MAX], 1e9);

    dijkstra();
    find_cost();

    for (long long i=1; i<=N; i++) {
        long long letter=seq[i-1]-96;
        for (long long j=1; j<=M; j++) {
            dp[i][j]=min(dp[i][j], dp[i-1][j]+cost[letter][j]);
            if (i>K) {
                dp[i][j]=min(dp[i][j], min_dp[i-K]+pfs_cost[i][j]-pfs_cost[i-K][j]);
            }
            min_dp[i]=min(min_dp[i], dp[i][j]);
        }
    }

    cout << min_dp[N];
}
