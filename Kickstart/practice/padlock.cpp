#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll N, D, dp[405][405][2]={}, num[405]={};

ll dist(int x, int y) {
    ll M=max(num[x], num[y]), m=min(num[x], num[y]);
    return min(M-m, (m-M+D)%D);
}

ll solve(int a, int b, int c) {
    if (dp[a][b][c]!=-1) return dp[a][b][c];
    dp[a][b][0]=min(solve(a+1, b, 0)+dist(a+1, a), solve(a+1, b, 1)+dist(b, a));
    dp[a][b][1]=min(solve(a, b-1, 0)+dist(a, b), solve(a, b-1, 1)+dist(b-1, b));
    return dp[a][b][c];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> D;
        fill(&dp[0][0][0], &dp[N+2][N+2][2], -1);
        fill(&num[0], &num[N+2], 0);
        for (int i=1; i<=N; i++) {
            cin >> num[i];
            dp[i][i][0]=0, dp[i][i][1]=0;
        }
        ll ans=min(solve(1, N, 0)+dist(1, 0), solve(1, N, 1)+dist(N, 0));
        cout << "Case #" << t << ": " << ans << "\n";
    }
}

/*
2
6 2
1 1 0 1 0 1
6 2
0 1 0 0 1 1

1
6 2
1 1 0 1 0 1

1
6 2
0 1 0 0 1 1
*/
