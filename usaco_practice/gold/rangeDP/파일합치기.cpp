#include <iostream>
#include <algorithm>
using namespace std;

const int K=505;
int dp[K][K]={};
int page[K]={};
int pfs[K]={};

int solve (int a, int b) {
    if (dp[a][b]!=1e9) return dp[a][b];

    for (int x=a; x<b; x++) {
        dp[a][b]=min(dp[a][b], solve(a, x)+solve(x+1, b)+pfs[b]-pfs[a-1]);
    }
    return dp[a][b];
}

int main()
{
    int T; cin >> T;
    for (int t=0; t<T; t++) {
        fill(&dp[0][0], &dp[K-1][K-1], 1e9);
        fill(&pfs[0], &pfs[K], 0);
        int k; cin >> k;
        for (int i=1; i<=k; i++) {
            cin >> page[i];
            dp[i][i]=page[i];
            pfs[i]=pfs[i-1]+page[i];
        }
        cout << solve(1, k)-pfs[k] << "\n";
    }
}
