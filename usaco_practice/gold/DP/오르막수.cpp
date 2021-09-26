#include <iostream>
#include <algorithm>
using namespace std;

int N, dp[1005][1005]={};

int main()
{
    cin >> N;
    for (int i=0; i<=9; i++) dp[1][i]=1;

    for (int i=2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            for (int k=0; k<=j; k++) {
                dp[i][j]+=dp[i-1][k];
                dp[i][j]%=10007;
            }
        }
    }

    long long ans=0;
    for (int i=0; i<=9; i++) ans+=dp[N][i];

    cout << ans%10007;
}
