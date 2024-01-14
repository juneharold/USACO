/*
dp[i][j]=the number of ways when the first i men are picked, and the set of women remaining are j.

if (a[i+1][k]) dp[i+1][j|(1<<k)]+=dp[i][j]
basecase dp[0][2^N-1] = 1
answer = dp[N][0]

time complexity: O(N*2^N*N)
*/
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll cntbits(ll x) {
    ll ret=0;
    while (x) {
        if (x%2) ret++;
        x/=2;
    }
    return ret;
}

const ll MOD=1e9+7;
ll a[22][22]={}, dp[22][1<<21]={};

int main()
{
    ll N; cin >> N;
    for (int i=1; i<=N; i++) for (int j=0; j<N; j++) cin >> a[i][j];
    dp[0][0]=1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<(1<<N); j++) {
            if (dp[i][j]!=0 && cntbits(j)==i) {
                for (int k=0; k<N; k++) {
                    if (a[i+1][k] && (j&(1<<k))==0) {
                        dp[i+1][j+(1<<k)]+=dp[i][j];
                        dp[i+1][j+(1<<k)]%=MOD;
                    }
                }
            }
        }
    }
    cout << dp[N][(1<<N)-1];
}