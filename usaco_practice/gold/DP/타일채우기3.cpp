#include <iostream>
#include <algorithm>
using namespace std;

const long long c=1e9+7;
const long long MAX_N=1e6+5;
long long dp[MAX_N][3]={};

int main()
{
    long long n; cin >> n;
    dp[1][0]=2; dp[1][1]=1; dp[1][2]=1;
    dp[2][0]=7; dp[2][1]=3; dp[2][2]=3;

    for (long long i=3; i<=n; i++) {
        dp[i][0]=(dp[i-1][0]*2+dp[i-2][0]+dp[i-1][1]+dp[i-1][2])%c;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%c;
        dp[i][2]=(dp[i-1][0]+dp[i-1][1])%c;
    }
    cout << dp[n][0]%c;
}
