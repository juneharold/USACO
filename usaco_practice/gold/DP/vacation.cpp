#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int MAX_N=1e5+5;
int activity[MAX_N][3]={};
int dp[MAX_N][3]={};

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=0; j<3; j++) {
        cin >> activity[i][j];
    }
    dp[1][0]=activity[1][0];
    dp[1][1]=activity[1][1];
    dp[1][2]=activity[1][2];
    for (int i=1; i<=n; i++) {
        for (int j=0; j<3; j++) {
            if (j==0) dp[i][j]=activity[i][j]+max(dp[i-1][j+1], dp[i-1][j+2]);
            if (j==1) dp[i][j]=activity[i][j]+max(dp[i-1][j-1], dp[i-1][j+1]);
            if (j==2) dp[i][j]=activity[i][j]+max(dp[i-1][j-1], dp[i-1][j-2]);
        }
    }
    int ans=0;
    for (int j=0; j<3; j++) ans=max(ans, dp[n][j]);
    cout << ans;
}
