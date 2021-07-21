#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1005;
int n;
int score[MAX_N]={};
int dp[MAX_N]={};

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> score[i];

    for (int i=1; i<=n; i++) {
        int hi=0, lo=1e5;
        for (int j=i; j>=1; j--) {
            hi=max(hi, score[j]); lo=min(lo, score[j]);
            dp[i]=max(dp[i], hi-lo+dp[j-1]);
        }
    }

    cout << dp[n];
}
