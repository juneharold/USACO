#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double dp[3000][3000]={}, p[3000]={};

int main()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> p[i];
    dp[1][1]=p[1], dp[1][0]=1.0-p[1];
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=i; j++) {
            if (j>0) dp[i][j]+=p[i]*dp[i-1][j-1];
            dp[i][j]+=(1.0-p[i])*dp[i-1][j];
        }
    }
    double ans=0;
    for (int j=n/2+1; j<=n; j++) ans+=dp[n][j];
    cout << fixed << setprecision(10) << ans;
}
