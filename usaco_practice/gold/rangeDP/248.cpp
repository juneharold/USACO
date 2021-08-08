#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=255;
int n, dp[MAX_N][MAX_N]={}, num[MAX_N]={};
int ans=0;

int main()
{
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    cin >> n;
    for (int i=0; i<n; i++) cin >> num[i];

    fill(&dp[0][0], &dp[n][n-1], -1);
    //int temp=solve(1, n);

    for (int i=1; i<=n; i++) {
        for (int a=0; a+i<=n; a++) {
            int b=i+a-1;
            if (i==1) {
                dp[a][b]=num[a];
            }
            for (int k=a; k<b; k++) {
                if (dp[a][k]==dp[k+1][b] && dp[a][k]>0) {
                    dp[a][b]=max(dp[a][b], dp[a][k]+1);
                }
            }
            ans=max(ans, dp[a][b]);
        }
    }
    cout << ans << "\n";

    /*
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/
}
