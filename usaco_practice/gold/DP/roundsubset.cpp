#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
int N, K, two[205], five[205], dp[2][201][26*201];

int main()
{
    cin >> N >> K;
    for (int i=1; i<=N; i++) {
        ll x; cin >> x;
        while (x%2==0) {
            two[i]++;
            x/=2;
        }
        while (x%5==0) {
            five[i]++;
            x/=5;
        }
    }

    fill(&dp[0][0][0], &dp[1][200][26*201], -1e9);
    int ans=0;
    dp[0][0][0]=0;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=K; j++) {
            for (int k=0; k<26*201; k++) {
                dp[i%2][j][k]=dp[(i+1)%2][j][k];
                if (j-1>=0 && k-five[i]>=0)
                    dp[i%2][j][k]=max(dp[i%2][j][k], dp[(i+1)%2][j-1][k-five[i]]+two[i]);
                ans=max(ans, min(k, dp[i%2][j][k]));
            }
        }
    }
    cout << ans;
}
