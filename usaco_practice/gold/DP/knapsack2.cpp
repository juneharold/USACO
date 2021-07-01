#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=105;
const int MAX_W=1e9+5;

int N, W;
int v[MAX_N]={}, w[MAX_N]={};
int dp[MAX_N][100005]={};

int main()
{
    cin >> N >> W;
    for (int i=1; i<=N; i++) cin >> w[i] >> v[i];

    for (int i=1; i<=N; i++) for (int j=0; j<100005; j++) dp[i][j]=1e9+1;

    dp[1][v[1]]=w[1];
    dp[1][0]=0;

    for (int i=2; i<=N; i++) {
        for (int j=0; j<100005; j++) {
            if (j>=v[i]) dp[i][j]=min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    int ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<100005; j++) {
            if (dp[i][j]<=W && j>ans) ans=j;
        }
    }
    cout << ans;
}
