#include <iostream>
#include <algorithm>
using namespace std;

const int MAX=755;
int arr[MAX][MAX], dp[MAX][MAX][4]={}, R, C;

int main()
{
    cin >> R >> C;
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) {
        char a; cin >> a;
        arr[i][j]=a-48;
    }

    for (int i=R; i>=1; i--) for (int j=1; j<=C; j++) {
        if (arr[i][j]==1) {
            dp[i][j][0]=dp[i+1][j-1][0]+1;
            dp[i][j][1]=dp[i+1][j+1][1]+1;
        }
    }
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) {
        if (arr[i][j]==1) {
            dp[i][j][2]=dp[i-1][j-1][2]+1;
            dp[i][j][3]=dp[i-1][j+1][3]+1;
        }
    }

    int ans=0;
    for (int i=1; i<=R; i++) for (int j=1; j<=C; j++) {
        if (arr[i][j]==0) continue;

        int maxlen=min(dp[i][j][0], dp[i][j][1]);
        for (int k=1; k<=maxlen; k++) {
            int ni=i+(k-1)*2;
            if (ni<=R && dp[ni][j][2]>=k && dp[ni][j][3]>=k) ans=max(ans, k);
        }

    }

    cout << ans;
}
