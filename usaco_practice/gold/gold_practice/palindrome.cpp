#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

const int MAX=2005;
int N, M, dp[MAX][MAX]={};
int cost[300]={};
string s;

int solve (int a, int b) {
    if (dp[a][b]!=1e9) return dp[a][b];

    if (a==b || (a+1==b && s[a]==s[b])) {
        dp[a][b]=0;
        return 0;
    }
    else {
        if (s[a]==s[b]) dp[a][b]=solve(a+1, b-1);
        dp[a][b]=min(dp[a][b], solve(a+1, b)+cost[s[a]]);
        dp[a][b]=min(dp[a][b], solve(a, b-1)+cost[s[b]]);
    }

    return dp[a][b];
}

int main()
{
    cin >> N >> M >> s;
    for (int i=0; i<N; i++) {
        char ch; int add, del;
        cin >> ch >> add >> del;
        cost[ch]=min(add, del);
    }

    fill(&dp[0][0], &dp[MAX-1][MAX-1], 1e9);

    cout << solve(0, M-1);
}
