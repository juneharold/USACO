#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second
const int MAX_N=505;
int n, dp[MAX_N][MAX_N]={};
pair<int, int> m[MAX_N];

int solve(int a, int b) {
    if (dp[a][b]!=1e9) return dp[a][b];
    if (a==b) return 0;
    if (a+1==b) {
        dp[a][b]=m[a].f*m[a].s*m[b].s;
        return dp[a][b];
    }
    for (int k=a; k<b; k++) {
        dp[a][b]=min(dp[a][b], solve(a, k)+solve(k+1, b)+m[a].f*m[k].s*m[b].s);
    }
    return dp[a][b];
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> m[i].f >> m[i].s;
    fill(&dp[0][0], &dp[MAX_N-1][MAX_N-1], 1e9);

    cout << solve(1, n);
}
