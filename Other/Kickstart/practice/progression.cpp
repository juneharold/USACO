#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll a[300005]={}, dp[300005][2]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll T; cin >> T;
    for (ll t=1; t<=T; t++) {
        //input
        ll N; cin >> N;
        for (ll i=1; i<=N; i++) cin >> a[i];
        a[0]=-1e18; a[N+1]=1e18;

        dp[1][0]=1;
        for (ll i=2; i<=N; i++) {
            dp[i][0]=2;
            if (a[i]-a[i-1]==a[i-1]-a[i-2]) dp[i][0]=max(dp[i][0], dp[i-1][0]+1);
        }
        dp[N][1]=1;
        for (ll i=N-1; i>=1; i--) {
            dp[i][1]=2;
            if (a[i]-a[i+1]==a[i+1]-a[i+2]) dp[i][1]=max(dp[i][1], dp[i+1][1]+1);
        }

        // finding ans;
        ll ans=3;
        for (ll i=1; i<=N; i++) {
            ll temp=0;
            if (i>=3 && i<=N-1 && a[i+1]==a[i-1]+2*(a[i-1]-a[i-2])) temp=1;
            ans=max(ans, dp[i-1][0]+1+temp);

            if (i>=2 && i<=N-2 && a[i-1]==a[i+1]+2*(a[i+1]-a[i+2])) temp=1;
            else temp=0;
            ans=max(ans, dp[i+1][1]+1+temp);

            if (i>=3 && i<=N-2 && a[i-1]-a[i-2]==a[i+2]-a[i+1] && a[i+1]==a[i-1]+2*(a[i-1]-a[i-2])) {
                ans=max(ans, dp[i-1][0]+1+dp[i+1][1]);
            }
        }
        cout << "Case #" << t << ": " << min(ans, N) << "\n";
        fill(&dp[0][0], &dp[300001][2], 0);
    }
}
