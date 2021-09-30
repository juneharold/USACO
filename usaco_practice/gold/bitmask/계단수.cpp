#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const int mod=1e9;
ll N, dp[105][15][(1<<10)];

int main()
{
    cin >> N;
    fill(&dp[0][0][0], &dp[104][14][(1<<10)], 0);
    for(int i=1; i<=9; i++) {
        dp[1][i][(1<<i)]=1;
    }

    ll ans=0;
    for (int i=2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<(1<<10); k++) {
                if (j+1<=9 && dp[i-1][j+1][k]!=0) {
                    dp[i][j][(k|(1<<j))]+=dp[i-1][j+1][k];
                    dp[i][j][(k|(1<<j))]%=mod;
                }
                if (j-1>=0 && dp[i-1][j-1][k]!=0) {
                    dp[i][j][(k|(1<<j))]+=dp[i-1][j-1][k];
                    dp[i][j][(k|(1<<j))]%=mod;
                }

                if (i==N && k==(1<<10)-1) {
                    ans+=dp[i][j][k];
                    ans%=mod;
                }
            }
        }
    }

    cout << ans;
}
