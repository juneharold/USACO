//벨만 포드 연습
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

vector<pair<pair<int, int>, int>> edge;
int dp[501]={};

void solve() {
    int n, m, w; cin >> n >> m >> w;
    edge.clear();
    for (int i=0; i<m; i++) {
        int u, v, d; cin >> u >> v >> d;
        edge.push_back({{u, v}, d});
        edge.push_back({{v, u}, d});
    }
    for (int i=0; i<w; i++) {
        int u, v, d; cin >> u >> v >> d;
        edge.push_back({{u, v}, -d});
    }

    fill(&dp[0], &dp[n+1], 1e9);
    dp[1]=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<edge.size(); j++) {
            int u=edge[j].f.f, v=edge[j].f.s, d=edge[j].s;
            if (i==n-1 && dp[u]+d<dp[v]) {
                cout << "YES\n";
                return;
            }
            dp[v]=min(dp[v], dp[u]+d);
        }
    }
    cout << "NO\n";
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}