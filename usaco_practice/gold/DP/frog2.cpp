#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
const int max_n=1e5+5;
int h[max_n]={};
int dp[max_n]={};

int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> h[i];
    dp[0]=0;
    dp[2]=abs(h[2]-h[1]);
    fill(&dp[3], &dp[max_n], 1e9);
    for (int i=3; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            if (i-j<1) break;
            dp[i]=min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    cout << dp[n];
}
