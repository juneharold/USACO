#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=505;
int mod = 1e9+7;
int n;
int dp[MAX_N][125250]={};

int main() {
    cin >> n;
    int target = n*(n+1)/2;
    if (target%2) {
        cout << 0;
        exit(0);
    }
    target/=2;

    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=target; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-i>=0) dp[i][j]+=dp[i-1][j-i];
            dp[i][j]%=mod;
        }
    }
    cout << dp[n-1][target] << "\n";
}
