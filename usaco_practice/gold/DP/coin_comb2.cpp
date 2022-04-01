#include <iostream>
#include <algorithm>
using namespace std;

const long long mod=1e9+7;
long long dp[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, coin[105]={}; cin >> n >> x;
    for (int i=0; i<n; i++) cin >> coin[i];

    for (int i=0; i<n; i++) {
        dp[coin[i]]+=1;
        for (int j=1; j<=x; j++) {
            if (coin[i]<j) dp[j]+=dp[j-coin[i]];
            dp[j]%=mod;
        }
    }
    cout << dp[x];
}
