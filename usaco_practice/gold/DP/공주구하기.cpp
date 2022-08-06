#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

int island[505][3], dp[505][505]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) for(int j=0; j<3; j++) cin >> island[i][j];

    dp[1][1]=1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int from=max(i, j)+1;
            dp[i][j]%=1000;
            for (int k=from; k<=N; k++) {
                if(island[k][0]-island[i][0]<=island[i][1]) {
                    dp[k][j]+=dp[i][j];
                }
            }
            for (int k=from; k<=N; k++) {
                if(island[k][0]-island[j][0]<=island[k][1] && island[k][2]) {
                    dp[i][k]+=dp[i][j];
                }
            }
        }
    }

    int ans=0;
    for (int j=1; j<N; j++) {
        if (island[N][0]-island[j][0]<=island[N][1]) {
            ans+=dp[N][j];
        }
    }
    cout << ans%1000;
}
