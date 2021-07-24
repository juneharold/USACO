#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=1005, MAX_M=2005;
int N, M, C;
int m[MAX_M]={};
vector<int> to_i[MAX_N];
int dp[2005][MAX_N];
int ans=0;

int main()
{
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> N >> M >> C;
    for (int i=1; i<=N; i++) cin >> m[i];
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        to_i[b].push_back(a);
    }

    dp[0][1]=0;
    for (int t=1; t<1005; t++) {
        for (int i=1; i<=N; i++) {
            for (int j=0; j<to_i[i].size(); j++) {
                if (dp[t-1][to_i[i][j]]==0 && to_i[i][j]!=1) continue;
                dp[t][i]=max(dp[t][i], dp[t-1][to_i[i][j]]+m[i]);
            }
        }
        ans=max(ans, dp[t][1]-C*t*t);
        //cout << t << " " << dp[t][1] << " " << C*t*t << "\n";
    }
    cout << ans;
}
