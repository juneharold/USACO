#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int MAX_N=105;
int x[MAX_N]={};
bool dp[MAX_N][100005]={};
set<int> ans;

int main()
{
    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        for (int j=i; j<=n; j++) dp[j][x[i]]=1;
    }

    dp[0][0]=true;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n*1000; j++) {
            if (dp[i-1][j]==true) dp[i][j]=true;
            if (j-x[i]>=0 && dp[i-1][j-x[i]]==true) dp[i][j]=true;

            if (dp[i][j]==true) ans.insert(j);
        }
    }


    cout << ans.size() << "\n";
    for (auto a: ans) cout << a << " ";
}
