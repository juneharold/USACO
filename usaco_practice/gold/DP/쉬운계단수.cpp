#include <iostream>
#include <algorithm>
using namespace std;

const int mod=1e9;
const int MAX_N=105;

int dp[MAX_N][10]={};

int main()
{
    int n; cin >> n;
    for (int j=1; j<=9; j++) dp[1][j]=1;

    for (int i=2; i<=n; i++) {
        for (int j=1; j<=8; j++) {
            dp[i][j]=(dp[i-1][j+1]+dp[i-1][j-1])%mod;
        }
        dp[i][0]=dp[i-1][1]%mod;
        dp[i][9]=dp[i-1][8]%mod;
    }
    long long ans=0;
    for (int j=0; j<=9; j++) ans+=dp[n][j];
    cout << ans%mod;
}
