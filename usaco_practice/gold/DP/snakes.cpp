#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=405;
int dp[MAX][MAX]={};
int a[MAX]={};
int N, K;

int main()
{
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> a[i];

    fill(&dp[0][0], &dp[MAX-1][MAX-1], 1e9);
    //basecase
    for (int j=0; j<=K; j++) {
        dp[1][j]=0;
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=K; j++) {

            if (j==0) {
                int M=a[i], S=a[i];
                for (int k=i-1; k>=1; k--) {
                    S+=a[k]; M=max(M, a[k]);
                }
                dp[i][j]=M*i-S;
            }
            else {
                int M=a[i], S=a[i];
                for (int k=i-1; k>=1; k--) {
                    dp[i][j]=min(dp[i][j], dp[k][j-1]+M*(i-k)-S);
                    S+=a[k]; M=max(M, a[k]);
                }
            }
        }
    }

    long long ans=1e9;
    for (int j=0; j<=K; j++) if (dp[N][j]<ans) ans=dp[N][j];
    cout << ans;
}
