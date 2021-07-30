#include <iostream>
#include <algorithm>
using namespace std;

const long long MAX_N=1e6+5, mod=1e9+7;
long long n;
long long dp[MAX_N]={};

int main()
{
    cin >> n;
    dp[0]=1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=6; j++) {
            if (i-j>=0) dp[i]+=dp[i-j];
        }
        dp[i]%=mod;
    }
    cout << dp[n];
}
