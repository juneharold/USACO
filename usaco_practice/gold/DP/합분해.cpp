#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const ll MAX=205;
ll N, K, dp[MAX][MAX]={};


int main()
{
    cin >> N >> K;
    fill(&dp[0][0], &dp[MAX-1][MAX], 0);

    for (int i=0; i<=N; i++) dp[1][i]=1;

    for (int i=2; i<=K; i++) {
        for (int j=0; j<=N; j++) {

            for (int n=0; n<=N; n++) {
                if (j-n>=0 && j-n<=N) dp[i][j]+=dp[i-1][j-n];
            }
        }
    }
    cout << dp[K][N];
}
