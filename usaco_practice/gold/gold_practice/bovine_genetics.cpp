/*
can extend substring from i-1 to i, or start new at i 

dp[i][j][k][l]=the answer until i, j is start letter to second to last substring, k is start letter of last substring, l is end letter of last substring

extend substring
s[i] or ? != l --> dp[i][j][k][s[i] or ?]+=dp[i-1][j][k][l]
start new substring 
dp[i][j][s[i] or ?][s[i] or ?]+=dp[i-1][j][s[i] or ?][l]

basecase dp[0][j][k][l]=1;
answer dp[n][j][k][s[i] or ?]
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll dp[nmax][4][4][4]={};
char s[nmax];
map<char, int> m={{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

void solve() {
    string temp; cin >> temp;
    int n=temp.size();
    for (int i=0; i<n; i++) s[i+1]=temp[i];

    for (int j=0; j<4; j++) {
        for (int l=0; l<4; l++) {
            if (m[s[1]]==l || s[1]=='?') dp[1][j][l][l]=1;
        }
    }

    for (int i=2; i<=n; i++) {
        for (int l=0; l<4; l++) {
            if (m[s[i]]==l || s[i]=='?') {
                for (int j=0; j<4; j++) {
                    for (int k=0; k<4; k++) {
                        for (int x=0; x<4; x++) {
                            if (l!=x) dp[i][j][k][l]+=dp[i-1][j][k][x];
                            dp[i][j][k][l]%=MOD;
                            if (j==x) dp[i][k][l][l]+=dp[i-1][j][k][x];
                            dp[i][k][l][l]%=MOD;
                        }
                    }
                }
            }
        }
    }

    ll ans=0;
    for (int k=0; k<4; k++) {
        for (int l=0; l<4; l++) {
            ans+=dp[n][l][k][l];
            ans%=MOD;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
