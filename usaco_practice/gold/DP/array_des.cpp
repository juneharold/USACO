#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_N=1e5+5, mod=1e9+7;
long long n, m, x[MAX_N]={};
long long dp[MAX_N][105]={};

int main()
{
    cin >> n >> m;
    for (long long i=1; i<=n; i++) cin >> x[i];

    //basecase
    if (x[1]==0) {
        for (long long i=1; i<=m; i++) dp[1][i]=1;
    }
    else {
        dp[1][x[1]]=1;
    }

    //dp
    for (long long i=2; i<=n; i++) {
        if (x[i]==0) {
            for (long long j=1; j<=m; j++) {
                if (j-1>=1) dp[i][j]+=dp[i-1][j-1];
                dp[i][j]+=dp[i-1][j];
                if (j+1<=m) dp[i][j]+=dp[i-1][j+1];

                dp[i][j]%=mod;
            }
        }
        else {
            if (x[i]-1>=1) dp[i][x[i]]+=dp[i-1][x[i]-1];
            dp[i][x[i]]+=dp[i-1][x[i]];
            if (x[i]+1<=m) dp[i][x[i]]+=dp[i-1][x[i]+1];

            dp[i][x[i]]%=mod;
        }
    }

    long long ans=0;
    if (x[n]==0) {
        for (long long j=1; j<=m; j++) {
            ans+=dp[n][j];
            ans%=mod;
        }
        cout << ans;
    }
    else {
        cout << dp[n][x[n]];
    }
}
