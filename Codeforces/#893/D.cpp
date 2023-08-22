#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> s(n+1); 
    for (ll i=1; i<=n; i++) {
        char c; cin >> c;
        s[i]=c-'0';
    }

    vector<vector<ll>> dp1(n+5, vector<ll>(k+5, 0)), dp2(n+5, vector<ll>(k+5, 0)); 
    // longest fur that ends at i and ends at j. 
    for (ll i=1; i<=n; i++) {
        ll cnt=k, len=0;
        for (ll j=i; j>=1; j--) {
            if (s[j]==0 && cnt==0) break;
            if (s[j]==0) cnt--;
            len++;
            dp1[i][cnt]=max(dp1[i][cnt], len);
        }
        dp1[i][cnt]=max(dp1[i][cnt], len);
    }
    for (ll i=n; i>=1; i--) {
        ll cnt=k, len=0;
        for (ll j=i; j<=n; j++) {
            if (s[j]==0 && cnt==0) break;
            if (s[j]==0) cnt--;
            len++;
            dp2[i][cnt]=max(dp2[i][cnt], len);
        }
        dp2[i][cnt]=max(dp2[i][cnt], len);
    }
    for (ll i=1; i<=n; i++) {
        for (ll j=k; j>=0; j--) {
            dp1[i][j]=max(dp1[i][j], dp1[i-1][j]);
            dp1[i][j]=max(dp1[i][j], dp1[i-1][j+1]);
            dp1[i][j]=max(dp1[i][j], dp1[i][j+1]);
        }
    }
    for (ll i=n; i>=1; i--) {
        for (ll j=k; j>=0; j--) {
            dp2[i][j]=max(dp2[i][j], dp2[i+1][j]);
            dp2[i][j]=max(dp2[i][j], dp2[i+1][j+1]);
            dp2[i][j]=max(dp2[i][j], dp2[i][j+1]);
        }
    }

    /*vector<vector<ll>> mxl(n+5, vector<ll>(k+5, -1)); // mxl[i]=the maximum length of l1 when l0 has length i
    for (ll i=1; i<=n; i++) {
        ll cnt=k, end=i-1;
        for (ll j=i; j<=n; j++) {
            if (s[j]==1 && cnt==0) break;
            if (s[j]==1) cnt--;
            end=j;
            mxl[]
        }
        //cout << "end: " << end << endl;
        mxl[(end-i+1)]=max(dp1[i-1], dp2[end+1]);
    }
    mxl[0]=dp1[n];*/
    //for (ll i=1; i<=n; i++) cout << dp1[i] << endl;
    //for (ll i=0; i<=n; i++) cout << mxl[i] << endl;
    vector<ll> mxl(n+5, -1); // mxl[i]=the maximum length of l1 when l0 has length i
    mxl[0]=dp1[n][0];
    for (ll i=1; i<=n; i++) {
        ll cnt=k, len=0, end=i+1;
        for (ll j=i; j>=1; j--) {
            if (s[j]==1 && cnt==0) break;
            if (s[j]==1) cnt--;
            len++;
            end=j;
            //ll res=max(dp1[j-1][k-cnt], dp2[i+1][k-cnt]);
            mxl[len]=max(mxl[len], max(dp1[j-1][k-cnt], dp2[i+1][k-cnt]));
        }
    }

    vector<ll> ans;
    for (ll i=1; i<=n; i++) {
        ll temp=0;
        for (ll j=0; j<=n; j++) { //
            if (mxl[j]==-1) continue;
            temp=max(temp, i*j+mxl[j]);
        }
        ans.push_back(temp);
    }
    for (ll x: ans) cout << x << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        solve();
    }
}
