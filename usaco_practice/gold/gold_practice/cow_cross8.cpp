#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=1005;
int N, top[MAX]={}, down[MAX]={}, dp[MAX][MAX]={};

int main()
{
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> top[i];
    for (int i=1; i<=N; i++) cin >> down[i];

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if (abs(top[i]-down[j])<=4) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            dp[i][j]=max(dp[i][j], dp[i-1][j]);
            dp[i][j]=max(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[N][N];
}
