#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX=55;
int dp[MAX][MAX]={};
string input;

int solve (int a, int b, string s) {
    if (dp[a][b]!=1e9) return dp[a][b];
    if (a>=b) return 0;

    else {
        if (s[a]==s[b]) dp[a][b]=solve(a+1, b-1, s);
        else dp[a][b]=solve(a+1, b-1, s)+1;
        dp[a][b]=min(dp[a][b], solve(a+1, b, s)+1);
        dp[a][b]=min(dp[a][b], solve(a, b-1, s)+1);
    }
    return dp[a][b];
}

int main()
{
    cin >> input;
    fill(&dp[0][0], &dp[MAX-1][MAX-1], 1e9);

    int ans=solve(0, input.size()-1, input);

    for (int i=0; i<input.size(); i++) {
        for (int j=i+1; j<input.size(); j++) {
            string temp=input;
            swap(temp[i], temp[j]);
            fill(&dp[0][0], &dp[MAX-1][MAX-1], 1e9);
            ans=min(ans, solve(0, input.size()-1, temp)+1);
        }
    }
    cout << ans;
}
