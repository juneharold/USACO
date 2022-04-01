#include <iostream>
#include <algorithm>
using namespace std;

int dp[10005][3]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        int wine; cin >> wine;
        dp[i][0]=max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1]=dp[i-1][0]+wine;
        dp[i][2]=max(dp[i-1][0], dp[i-1][1])+wine;
    }
    cout << max(dp[N][0], max(dp[N][1], dp[N][2]));
}
