#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

ll change(char c) {
    ll ret=1;
    for (ll i=0; i<c-'A'; i++) ret*=10;
    return ret;
}

ll dp[200005][5][2]={};

int main()
{
    ll T; cin >> T;
    while (T--) {
        string s; cin >> s;
        ll n=s.size();
        reverse(s.begin(), s.end());
        fill(&dp[0][0][0], &dp[n+1][5][2], -1e18);
        for (ll j=0; j<5; j++) {
            if (s[0]-'A'==j) dp[0][j][0]=change(j+'A');
            else dp[0][j][1]=change(j+'A');
        }
        for (ll i=1; i<n; i++) {
            for (ll j=0; j<5; j++) {
                if (s[i]-'A'>=j) {
                    dp[i][s[i]-'A'][0]=max(dp[i][s[i]-'A'][0], dp[i-1][j][0]+change(s[i]));
                    dp[i][s[i]-'A'][1]=max(dp[i][s[i]-'A'][1], dp[i-1][j][1]+change(s[i]));
                }
                if (s[i]-'A'<j) {
                    dp[i][j][0]=max(dp[i][j][0], dp[i-1][j][0]-change(s[i]));
                    dp[i][j][1]=max(dp[i][j][1], dp[i-1][j][1]-change(s[i]));
                }
                if (j!=s[i]-'A') {
                    for (ll k=0; k<5; k++) {
                        if (j>=k) dp[i][j][1]=max(dp[i][j][1], dp[i-1][k][0]+change(j+'A'));
                        else dp[i][k][1]=max(dp[i][k][1], dp[i-1][k][0]-change(j+'A'));
                    }
                }
            }
        }

        ll ans=-1e18;
        for (ll j=0; j<5; j++) for (ll k=0; k<2; k++) ans=max(ans, dp[n-1][j][k]);
        cout << ans << "\n";
    }
}
/*
1
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDEED
*/