#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=1e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

ll k;
string s;

pair<ll, pii> dp[nmax][2][2];

pair<ll, pii> DP(ll x, ll y, ll z) {
    if (s.size()==x) return {0, {1, 1}};
    if (dp[x][y][z].fs!=-1) return dp[x][y][z];
    dp[x][y][z]={0, {0, 0}};
    int to=(y ? 9 : s[x]-'0');
    for (ll i=0; i<=to; i++) {
        ll nx=x+1;
        ll ny=(y || i<s[x]-'0' ? 1 : 0);
        ll nz=(z || i>0 ? 1 : 0);
        if (i==k || (i==0 && z==0)) {
            auto res=DP(nx, ny, nz);
            dp[x][y][z].fs+=res.fs;
            dp[x][y][z].sc.fs+=res.sc.fs;
            dp[x][y][z].sc.sc+=res.sc.sc;
        }
        else {
            auto res=DP(nx, ny, nz);
            dp[x][y][z].fs+=res.fs+i*res.sc.sc;
            dp[x][y][z].sc.fs+=res.sc.fs;
            dp[x][y][z].sc.sc+=10*res.sc.sc;
        }
    }
    dp[x][y][z].fs%=MOD;
    dp[x][y][z].sc.fs%=MOD;
    dp[x][y][z].sc.sc%=MOD;
    return dp[x][y][z];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> s;
    memset(dp, -1, sizeof(dp));
    cout << DP(0, 0, 0).fs;
}
