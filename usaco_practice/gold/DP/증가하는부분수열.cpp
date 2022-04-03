#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005]={}, num[1005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> num[i];

    int ans=0;
    for (int i=1; i<=N; i++) {
        for (int j=i-1; j>=0; j--) {
            if (num[j]<num[i]) dp[i]=max(dp[i], dp[j]+1);
        }
        ans=max(ans, dp[i]);
    }

    cout << ans;
}
