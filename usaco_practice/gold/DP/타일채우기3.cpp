#include <iostream>
#include <algorithm>
using namespace std;

const int c=1e9+7;
const int MAX_N=1e6+5;
int dp[MAX_N]={};

int main()
{
    int n; cin >> n;
    dp[1]=2;
    dp[2]=7;
    for (int i=3; i<=n; i++) {
        dp[i]=(dp[i-1]+dp[i-1]+dp[i-2]+dp[i-2]+dp[i-2])%c;
    }
    cout << dp[n];
}
