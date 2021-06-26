#include <iostream>
using namespace std;

const int MAX_N=105;
const int MAX_W=1e5+5;

int N, W;
int w[MAX_N]={};
int v[MAX_N]={};
int dp[MAX_N][MAX_W]={};

int main()
{
    cin >> N >> W;
    for (int i=1; i<=N; i++) cin >> w[i] >> v[i];
    dp[1][W]=0;
    dp[1][W-w[1]]=v[1];

    long long ans=0;
    for (int i=2; i<=N; i++) {
        for (int j=1; j<=W; j++) {

            dp[i][j]=dp[]
        }
    }
    cout << ans;
}
