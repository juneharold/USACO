#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll N, D, dp[405][405]={}, num[405][405]={};

ll dist(int x1, int y1, int x2, int y2) {
    ll M=max(num[x1][y1], num[x2][y2]), m=min(num[x1][y1], num[x2][y2]);
    return min(M-m, (m-M+D)%D);
}

ll solve(int a, int b) {
    if (dp[a][b]!=-1) return dp[a][b];
    
    ll temp1=solve(a, b-1)+dist(b, b, a, b-1), temp2=solve(a+1, b)+dist(a, a, a+1, b);
    if (temp1<temp2) {
        dp[a][b]=temp1;
        num[a][b]=num[b][b];
    }
    else {
        dp[a][b]=temp2;
        num[a][b]=num[a][a];
    }
    return dp[a][b];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> D;
        fill(&dp[0][0], &dp[N+2][N+2], -1);
        for (int i=1; i<=N; i++) {
            int x; cin >> x;
            num[i][i]=x;
            dp[i][i]=0;
        }
        cout << "Case #" << t << ": " << solve(1, N)+dist(0, 0, 1, N) << "\n";
        fill(&num[0][0], &num[N+2][N+2], 0);
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
