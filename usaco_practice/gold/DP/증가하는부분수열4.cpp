#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1005]={}, num[1005]={}, from[1005];
vector<int> path;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> num[i];

    int ans=0, cur;
    for (int i=1; i<=N; i++) {
        for (int j=i-1; j>=0; j--) {
            if (num[j]<num[i] && dp[j]+1>dp[i]) {
                dp[i]=dp[j]+1;
                from[i]=j;
            }
        }
        if (dp[i]>ans) {
            ans=dp[i];
            cur=i;
        }
    }
    cout << ans << "\n";

    while (cur!=0) {
        path.push_back(num[cur]);
        cur=from[cur];
    }
    for (int i=path.size()-1; i>=0; i--) cout << path[i] << " ";
}
