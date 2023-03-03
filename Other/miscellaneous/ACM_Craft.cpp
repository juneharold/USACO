#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int D[1005]={}, in[1005]={}, dp[1005]={};
vector<int> bef[1005], nxt[1005];

int main()
{
    int T; cin >> T;
    while (T--) {
        int N, K, W; cin >> N >> K;
        for (int i=1; i<=N; i++) cin >> D[i];
        for (int i=1; i<=K; i++) {
            int x, y; cin >> x >> y;
            bef[y].push_back(x);
            in[y]++;
            nxt[x].push_back(y);
        }
        cin >> W;

        queue<int> q;
        for (int i=1; i<=N; i++) {
            if (in[i]==0) q.push(i);
        }

        while (!q.empty()) {
            int cur=q.front(); q.pop();
            dp[cur]=D[cur];
            for (int before: bef[cur]) {
                dp[cur]=max(dp[cur], dp[before]+D[cur]);
            }

            for (int nx: nxt[cur]) {
                in[nx]--;
                if (in[nx]==0) q.push(nx);
            }
        }

        cout << dp[W] << "\n";

        for (int i=1; i<=N; i++) {
            D[i]=0, in[i]=0, dp[i]=0;
            bef[i].clear();
            nxt[i].clear();
        }
    }
}

/*
1
4 4
10 1 100 10
1 2
1 3
2 4
3 4
4
*/
