#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const long long MAX=105;
long long N, K, r[MAX*2]={}, dp[MAX][2*MAX][8]={}; //sing polong long, current, #open door

int main()
{
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    cin >> N >> K;
    for (long long i=1; i<=N; i++) cin >> r[i];
    for (long long i=N+1; i<=2*N; i++) r[i]=r[i-N];


    fill(&dp[0][0][0], &dp[MAX-1][2*MAX-1][8], 1e9);


    for (long long s=1; s<=N; s++) {
        dp[s][s][1]=0;

        for (long long n=s; n<=s+N; n++) {

            dp[s][n][1]=min(dp[s][n][1], dp[s][n-1][1]+(n-s)*r[n]);
            for (long long k=2; k<=K; k++) {
                dp[s][n][k]=min(dp[s][n][k], dp[s][n-1][k-1]);

                long long res=0, pfs=r[n];
                for (long long l=n-1; l>s; l--) {
                    res+=pfs;
                    dp[s][n][k]=min(dp[s][n][k], dp[s][l-1][k-1]+res);
                    pfs+=r[l];
                }
            }
        }
    }

    long long ans=1e9;
    for (long long i=0; i<N; i++) ans=min(ans, dp[i][i+N-1][K]);

    cout << ans;
}
