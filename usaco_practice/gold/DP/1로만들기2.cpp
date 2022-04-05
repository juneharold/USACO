#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000005]={}, from[1000005]={};
vector<int> path;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    fill(&dp[0], &dp[N], 1e9);
    for (int i=N-1; i>=1; i--) {
        if (i*2<=N) {
            dp[i]=dp[i*2]+1;
            from[i]=i*2;
        }
        if (i*3<=N && dp[i*3]+1<dp[i]) {
            dp[i]=dp[i*3]+1;
            from[i]=i*3;
        }
        if (i+1<=N && dp[i+1]+1<dp[i]) {
            dp[i]=dp[i+1]+1;
            from[i]=i+1;
        }
    }
    cout << dp[1] << "\n";

    int cur=1;
    while (cur!=0) {
        path.push_back(cur);
        cur=from[cur];
    }

    for (int i=path.size()-1; i>=0; i--) cout << path[i] << " ";
}
