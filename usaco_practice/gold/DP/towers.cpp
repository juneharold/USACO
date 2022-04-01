#include <iostream>
#include <algorithm>
using namespace std;

const long long mod=1e9+7;
long long dp[1000005][2]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    dp[1][0]=1;dp[1][1]=1;
    for (int i=2; i<=1e6; i++) {
        dp[i][0]=(4*dp[i-1][0]+dp[i-1][1])%mod;
        dp[i][1]=(2*dp[i-1][1]+dp[i-1][0])%mod;
    }

    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        cout << (dp[x][0]+dp[x][1])%mod << "\n";
    }
}
