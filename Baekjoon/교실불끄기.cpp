#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define f first
#define s second
const ll nmax=100005;

ll dp[nmax][3]={}, a1[nmax]={}, a2[nmax]={}, mxdiff[nmax]={};

int main()
{
    ll n, m; cin >> n >> m;
    fill(&a1[1], &a1[n+1], m+1);
    fill(&a2[1], &a2[n+1], 0);
    fill(&mxdiff[1], &mxdiff[n+1], 0);
    for (ll i=1; i<=n; i++) {
        ll k; cin >> k;
        ll prev=0;
        for (ll j=1; j<=k; j++) {
            ll x; cin >> x;
            if (j==1) a1[i]=x;
            if (j==k) a2[i]=x;
            mxdiff[i]=max(mxdiff[i], x-prev);
            prev=x;
        }
        mxdiff[i]=max(mxdiff[i], m+1-prev);
    }

    fill(&dp[0][0], &dp[n+1][2], 1e18);
    dp[n][0]=2*m;
    dp[n][1]=m+1;
    dp[n][2]=2*m;
    for (ll i=n-1; i>=1; i--) {
        dp[i][0]=min(dp[i][0], dp[i+1][0]+2*a2[i]+2);
        dp[i][0]=min(dp[i][0], dp[i+1][1]+(m+1)+2);
        dp[i][0]=min(dp[i][0], dp[i+1][2]+2*(m+1)+2);

        dp[i][1]=min(dp[i][1], dp[i+1][0]+(m+1)+2);
        dp[i][1]=min(dp[i][1], dp[i+1][1]+2*(m+1-mxdiff[i])+2);
        dp[i][1]=min(dp[i][1], dp[i+1][2]+(m+1)+2);

        dp[i][2]=min(dp[i][2], dp[i+1][0]+2*(m+1)+2);
        dp[i][2]=min(dp[i][2], dp[i+1][1]+(m+1)+2);
        dp[i][2]=min(dp[i][2], dp[i+1][2]+2*(m+1-a1[i])+2);
    }
    cout << min(dp[1][0], dp[1][1]);
}

/*
4 3
2 1 3
2 1 3
2 1 3
3 1 2 3 
*/