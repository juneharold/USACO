/*
dp[i][j]=length of LCS in 1~i of string s and 1~j of string t
if (s[i]==s[j]) dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=dp[i-1][j-1];
basecase: dp[0][0]=0;
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int dp[3001][3001]={};
pair<int, int> from[3001][3001]={};

int main()
{
    string s, t; cin >> s >> t;
    int n=s.size(), m=t.size();
    fill(&dp[0][0], &dp[n][m+1], -1e9);
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i-1]==t[j-1] && dp[i-1][j-1]+1>dp[i][j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                from[i][j]={i-1, j-1};
            }
            else {
                if (dp[i-1][j]>dp[i][j-1]) {
                    dp[i][j]=dp[i-1][j];
                    from[i][j]={i-1, j};
                }
                else {
                    dp[i][j]=dp[i][j-1];
                    from[i][j]={i, j-1};
                }
            }
        }
    }

    string ans="";
    int x=n, y=m;
    while (x>0 && y>0) {
        if (s[x-1]==t[y-1]) ans+=s[x-1];
        auto temp=from[x][y];
        x=temp.first, y=temp.second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}