#include <iostream>
#include <algorithm>
using namespace std;

const long long cons=1e9+7;
long long dp[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x; cin >> n >> x;
    int coin[105]={};
    for (int i=0; i<n; i++) {
        cin >> coin[i];
        dp[coin[i]]=1;
    }

    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (coin[j]<i) dp[i]+=dp[i-coin[j]];
        }
        dp[i]%=cons;
    }
    cout << dp[x];
}
