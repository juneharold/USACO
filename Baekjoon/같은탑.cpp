#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int h[55]={}, dp[55][500005]={};

int main()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> h[i];
    fill(&dp[0][0], &dp[50][500001], -1e9);
    dp[0][0]=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=500000; j++) {
            dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
            if (j+h[i+1]<=500000) dp[i+1][j+h[i+1]]=max(dp[i+1][j+h[i+1]], dp[i][j]+h[i+1]);
            if (h[i+1]-j>0) dp[i+1][h[i+1]-j]=max(dp[i+1][h[i+1]-j], dp[i][j]+h[i+1]-j);
            else dp[i+1][j-h[i+1]]=max(dp[i+1][j-h[i+1]], dp[i][j]);
        }
    }

    if (dp[n][0]>0) cout << dp[n][0];
    else cout << -1;
}