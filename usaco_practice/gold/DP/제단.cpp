#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const ll mod=1e9+7;
ll dp[2][10005]={}, h[10005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> h[i];
    if (h[1]>0 || h[N]>0) {
        cout << 0;
        exit(0);
    }

    h[1]=0, h[N]=0;
    dp[1][0]=1;
    for (int i=2; i<=N; i++) {
        int cur=i%2, bef=(i-1)%2;
        fill(&dp[cur][0], &dp[cur][10000], 0);
        if (h[i]!=-1) {
            dp[cur][h[i]]+=dp[bef][h[i]]+dp[bef][h[i]+1];
            if (h[i]>0) dp[cur][h[i]]+=dp[bef][h[i]-1];
            dp[cur][h[i]]%=mod;
        }
        else {
            for (int j=0; j<=10000; j++) {
                dp[cur][j]+=dp[bef][j+1]+dp[bef][j];
                if (j>0) dp[cur][j]+=dp[bef][j-1];
                dp[cur][j]%=mod;
            }
        }
    }
    cout << dp[N%2][0];
}
