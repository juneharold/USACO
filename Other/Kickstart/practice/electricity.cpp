#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[200005]={}, dp[200005]={};
vector<int> graph[200005];

int solve(int cur) {
    if (dp[cur]!=-1) return dp[cur];
    dp[cur]=1;
    for (int nx: graph[cur]) {
        if (A[cur]>A[nx]) dp[cur]+=solve(nx);
    }
    return dp[cur];
}

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N; cin >> N;
        for (int i=1; i<=N; i++) cin >> A[i];
        for (int i=1; i<=N-1; i++) {
            int a, b; cin >> a >> b;
            if (A[a]<A[b]) graph[b].push_back(a);
            if (A[a]>A[b]) graph[a].push_back(b);
        }

        fill(&dp[0], &dp[N+1], -1);
        for (int i=1; i<=N; i++) {
            if (dp[i]==-1) solve(i);
        }

        int ans=0;
        for (int i=1; i<=N; i++) {
            ans=max(ans, dp[i]);
        }
        cout << "Case #" << t << ": " << ans << "\n";
        for (int i=1; i<=N; i++) {
            A[i]=0;
            graph[i].clear();
        }
    }
}
