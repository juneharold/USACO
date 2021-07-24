#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1e4+5;
int dp[MAX_N]={};
int a[MAX_N]={};

int main()
{
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    int n, k; cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<=n; i++) {
        int M=a[i];
        for (int j=i-1; j>=i-k; j--) {
            if (j>=0) dp[i]=max(dp[i], dp[j]+M*(i-j));
            M=max(M, a[j]);
        }
    }
    cout << dp[n];
}
