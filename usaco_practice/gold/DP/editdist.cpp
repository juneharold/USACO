#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAX=5005;
string s1, s2;
int dp[MAX][MAX]={};

int main()
{
    cin >> s1 >> s2;
    fill(&dp[0][0], &dp[MAX-1][MAX-1], 1e9);

    for (int i=0; i<=s1.size(); i++) {
        for (int j=0; j<=s2.size(); j++) {
            if (i==0) {
                dp[i][j]=j;
            }
            else if (j==0) {
                dp[i][j]=i;
            }
            else if (s1[i-1]==s2[j-1]) {
                dp[i][j]=dp[i-1][j-1];
            }
            else {
                dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
                dp[i][j]=min(dp[i][j], dp[i-1][j-1]+1); //replace
            }
        }
    }
    cout << dp[s1.size()][s2.size()];

}
