#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=105;
int N, record[MAX]={}, dp[MAX][MAX][MAX]={};

int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    cin >> N;
    for (int i=1; i<=N; i++) cin >> record[i];

    fill(&dp[0][0][0], &dp[101][101][101], -999);

    dp[0][0][0]=0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            for (int k=0; k<=i-j; k++) {
                if (record[i]==0) {
                    dp[i][j][0]=max(dp[i][j][0], dp[i-1][j-1][k]+1);
                }
                else {
                    dp[i][j][0]=max(dp[i][j][0], dp[i-1][j-1][k]);
                }

                if (record[i]==k) {
                    dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]+1);
                }
                else {
                    dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1]);
                }
            }
        }
    }

    for (int j=1; j<=N; j++) {
        int ans=0;
        for (int k=0; k<N; k++) {
            ans=max(ans, dp[N][j][k]);
        }
        cout << N-ans << "\n";
    }
}

/*
4
1 2 1 2
*/
