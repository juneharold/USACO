#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int dp[30005][305]={}, gem[30005]={}, jump[305]={};

int main()
{
    int N, D; cin >> N >> D;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        gem[x]+=1;
    }
    int sum=0, until=D, from=D, cnt=0;
    while (sum<30000) {
        sum+=until;
        until++;
        cnt++;
    }
    sum=0;
    while (sum<30000 && from>=1) {
        sum+=from;
        from--;
        cnt++;
    }
    int start;
    for (int i=1; i<=cnt; i++) {
        jump[i]=++from;
        if (jump[i]==D) start=i;
    }

    fill(&dp[0][0], &dp[30001][301], -1e9);
    dp[D][start]=gem[D];

    int ans=0;
    for (int i=D; i<=30000; i++) {
        for (int j=1; j<=cnt; j++) {
            if (i+jump[j-1]<=30000 && j-1>0)
                dp[i+jump[j-1]][j-1]=max(dp[i+jump[j-1]][j-1], dp[i][j]+gem[i+jump[j-1]]);
            if (i+jump[j]<=30000)
                dp[i+jump[j]][j]=max(dp[i+jump[j]][j], dp[i][j]+gem[i+jump[j]]);
            if (i+jump[j+1]<=30000)
                dp[i+jump[j+1]][j+1]=max(dp[i+jump[j+1]][j+1], dp[i][j]+gem[i+jump[j+1]]);
            ans=max(ans, dp[i][j]);
        }
    }
    cout << ans;
}

/*
1 30000
30000
*/
