#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MAX=3005;
string s, t;
int dp[MAX][MAX]={};

int main()
{
    cin >> s >> t;
    for (int i=1; i<=s.size(); i++) {
        for (int j=1; j<=t.size(); j++) {
            if (s[i-1]==t[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
                dp[i][j]=max(dp[i][j], dp[i][j-1]);
            }
        }
    }


    vector <char> ans;
    int i=s.size(), j=t.size();
    while (i>0 && j>0) {
        if (dp[i-1][j-1]+1==dp[i][j] && s[i-1]==t[j-1]) {
            i--; j--;
            ans.push_back(s[i]); //순서 맞게
        }
        else if (dp[i][j-1]>dp[i-1][j]) {
            j--;
        }
        else {
            i--;
        }
    }
    int from=ans.size()-1;
    for (int a=from; a>=0; a--) cout << ans[a];
}
