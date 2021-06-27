#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=105;
const int MAX_W=1e5+5;

int N, W;
int w[MAX_N]={};
int v[MAX_N]={};
long long dp[MAX_N][MAX_W]={};

int main()
{
    cin >> N >> W;
    for (int i=1; i<=N; i++) cin >> w[i] >> v[i];

    for (int j=0; j<=W; j++) {
        if (j>=w[1]) dp[1][j]=v[1];
    }

    long long ans=0;
    for (int i=2; i<=N; i++) {
        for (int j=0; j<=W; j++) {
            if (j>=w[i]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout << dp[N][W];
}
