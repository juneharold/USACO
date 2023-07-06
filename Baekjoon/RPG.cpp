#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, q[55][3]={}, dp[1005][1005]={}, vst[55]={};

int solve(int i, int j) {
    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=0;
    vector<int> quest; 
    int point=0;
    for (int k=1; k<=n; k++) {
        if (q[k][0]<=i || q[k][1]<=j) {
            dp[i][j]++;
            if (vst[k]) continue;
            point+=q[k][2];
            vst[k]=1;
            quest.push_back(k);
        }
    }
    for (int a=0; a<=point; a++) {
        dp[i][j]=max(dp[i][j], solve(min(1000, i+a), min(1000, j+point-a)));
    }
    for (int x: quest) vst[x]=0;
    return dp[i][j];
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) for (int j=0; j<3; j++) cin >> q[i][j];
    fill(&dp[0][0], &dp[1000][1001], -1);
    cout << solve(1, 1);
}