#include <iostream>
#include <algorithm>
using namespace std;

int a[100005]={}, dp[100005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    
    for (int i=1; i<=N; i++) {
        if (i-1>=1 && a[i]==a[i-1]) dp[i]=2;
        else dp[i]=1;
    }

    int ans=0;
    for (int i=2; i<=N; i++) {
        if (a[i]==a[i-dp[i-1]-1] && a[i]<a[i-1]) {
            dp[i]=dp[i-1]+2;
        }
        ans=max(ans, dp[i]);
    }
    cout << ans;
}
