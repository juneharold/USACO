#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    for (int t=0; t<T; t++) {
        int n; cin >> n;
        int dp[15]={};
        dp[1]=1; dp[2]=2; dp[3]=4;
        for (int i=4; i<=n; i++) dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        cout << dp[n] << "\n";
    }
}
