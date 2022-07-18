#include <iostream>
#include <algorithm>
using namespace std;

int N, K, a[205]={}, dp[205][205]={};

int solve (int i, int j) {
    if (i>j) return 1e9;
    if (dp[i][j]!=1e9) return dp[i][j];

    for (int k=i; k<=j-1; k++) {
        if (a[i]==a[k+1]) dp[i][j]=min(dp[i][j], solve(i, k)+solve(k+1, j));
        dp[i][j]=min(dp[i][j], solve(i, k)+solve(k+1, j)+1);
    }

    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> a[i];
    fill(&dp[0][0], &dp[204][204], 1e9);

    for (int i=1; i<=N; i++) {
        int idx=i;
        for (int j=i; j<=N; j++) {
            if (a[j]==a[i]) dp[i][j]=0;
            else break;
        }
        dp[i][idx]=0;
    }

    cout << solve(1, N);
}
