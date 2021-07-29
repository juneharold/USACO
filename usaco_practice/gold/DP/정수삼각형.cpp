#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=505;
int val[MAX_N][MAX_N]={}, dp[MAX_N][MAX_N]={};
int n;

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=1; j<=i; j++) cin >> val[i][j];

    dp[1][1]=val[1][1];
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j]=max(dp[i-1][j-1], dp[i-1][j])+val[i][j];
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) ans=max(ans, dp[n][i]);
    cout << ans;
}
