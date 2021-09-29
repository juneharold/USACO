#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll N, dp[105][21]={}, num[105];

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> num[i];

    fill(&dp[0][0], &dp[104][21], 0);
    dp[1][num[1]]=1;

    for (int i=2; i<=N; i++) {
        for (int j=0; j<=20; j++) {
            if (j-num[i]>=0 && dp[i-1][j-num[i]]!=0) dp[i][j]+=dp[i-1][j-num[i]];
            if (j+num[i]<=20 && dp[i-1][j+num[i]]!=0) dp[i][j]+=dp[i-1][j+num[i]];
        }
    }

    cout << dp[N-1][num[N]];
}
