#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1005;
const int MAX_X=1e5+5;

int N, X;
int price[MAX_N]={};
int pages[MAX_N]={};
int dp[MAX_N][MAX_X]={};

int main()
{
    cin >> N >> X;
    for (int i=1; i<=N; i++) cin >> price[i];
    for (int i=1; i<=X; i++) cin >> pages[i];

    for (int j=0; j<=X; j++) {
        if (j>=price[1]) dp[1][j]=pages[1];
    }

    int ans=0;
    for (int i=2; i<=N; i++) {
        for (int j=0; j<=X; j++) {
            if (j>=price[i]) dp[i][j]=max(dp[i-1][j], dp[i-1][j-price[i]]+pages[i]);
            else dp[i][j]=dp[i-1][j];

            ans=max(ans, dp[i][j]);
        }
    }

    cout << ans;
}
