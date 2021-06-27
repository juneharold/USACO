#include <iostream>
#include <algorithm>
using namespace std;

const int max_n=1e5+5;
int h[max_n]={};
int dp[max_n]={};

int main()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) cin >> h[i];
    dp[1]=0;
    dp[2]=abs(h[2]-h[1]);
    for (int i=3; i<=n; i++) {
        dp[i]=min(dp[i-2]+abs(h[i]-h[i-2]), dp[i-1]+abs(h[i]-h[i-1]));
    }
    cout << dp[n];
    return 0;
}
