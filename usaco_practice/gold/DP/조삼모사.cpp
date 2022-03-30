#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int N, K, C, dp[1000005]={}, w[1000005]={};
pair<int, int> path[1000005]={};
vector<int> ans;

void find_path(int cur) {
    if (cur<1) return;
    int bef=path[cur].f, type=path[cur].s;
    if (type==1) ans.push_back(cur-K+1);
    find_path(bef);
}

int main()
{
    cin >> N >> K >> C;
    for (int i=1; i<=N; i++) cin >> w[i];

    fill(&dp[1], &dp[N+1], 1e9);

    for (int i=1; i<=N; i++) {
        dp[i]=min(dp[i], dp[i-1]+w[i]);
        if (i>=K && dp[i-K]+C<dp[i]) {
            dp[i]=dp[i-K]+C;
            path[i]={i-K, 1};
        }
        else {
            path[i]={i-1, 0};
        }
    }

    find_path(N);

    cout << dp[N] << "\n" << ans.size() << "\n";
    for (int x: ans) cout << x << "\n";
}
