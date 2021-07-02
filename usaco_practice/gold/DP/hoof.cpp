#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1e5+5;
const int MAX_K=25;
int N, K;
int dp[MAX_N][MAX_K][4]={}; //1=hoof, 2=paper, 3=scissor
char fj[MAX_N]={};

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> N >> K;
    for (int i=1; i<=N; i++) cin >> fj[i];

    if (fj[1]=='H'){
        dp[1][1][1]=0; dp[1][1][2]=1; dp[1][1][3]=0;
    }
    else if (fj[1]=='P') {
        dp[1][1][1]=0; dp[1][1][2]=0; dp[1][1][3]=1;
    }
    else {
        dp[1][1][1]=1; dp[1][1][2]=0; dp[1][1][3]=0;
    }

    for (int i=2; i<=N; i++) {
        for (int j=1; j<=K+1; j++) {
            if (fj[i]=='H') {
                dp[i][j][1]=dp[i-1][j][1];
                dp[i][j][2]=max(dp[i-1][j][2]+1, max(dp[i-1][j-1][1]+1, dp[i-1][j-1][3]+1));
                dp[i][j][3]=dp[i-1][j][3];
            }
            if (fj[i]=='P') {
                dp[i][j][1]=dp[i-1][j][1];
                dp[i][j][2]=dp[i-1][j][2];
                dp[i][j][3]=max(dp[i-1][j][3]+1, max(dp[i-1][j-1][1]+1, dp[i-1][j-1][2]+1));
            }
            if (fj[i]=='S') {
                dp[i][j][1]=max(dp[i-1][j][1]+1, max(dp[i-1][j-1][2]+1, dp[i-1][j-1][3]+1));
                dp[i][j][2]=dp[i-1][j][2];
                dp[i][j][3]=dp[i-1][j][3];
            }
        }
    }

    int ans=0;
    for (int j=1; j<=K+1; j++) {
        for (int k=1; k<=3; k++) {
            if (dp[N][j][k]>ans) ans=dp[N][j][k];
        }
    }
    cout << ans;
}
