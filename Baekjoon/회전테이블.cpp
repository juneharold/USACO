#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

ll N, A[105]={}, B[105]={}, C[105]={}, dp[105][105][105][10]={};

ll cost(ll who, ll i, ll j, ll k, ll x) {
    if (who==0) {
        if (x==0) return min((A[i+1]-A[i]+N)%N, (A[i]-A[i+1]+N)%N);
        if (x==1) return min((A[i+1]-B[j]+N)%N, (B[j]-A[i+1]+N)%N);
        if (x==2) return min((A[i+1]-C[k]+N)%N, (C[k]-A[i+1]+N)%N);
    }
    if (who==1) {
        if (x==0) return min((B[j+1]-A[i]+N)%N, (A[i]-B[j+1]+N)%N);
        if (x==1) return min((B[j+1]-B[j]+N)%N, (B[j]-B[j+1]+N)%N);
        if (x==2) return min((B[j+1]-C[k]+N)%N, (C[k]-B[j+1]+N)%N);
    }
    if (who==2) {
        if (x==0) return min((C[k+1]-A[i]+N)%N, (A[i]-C[k+1]+N)%N);
        if (x==1) return min((C[k+1]-B[j]+N)%N, (B[j]-C[k+1]+N)%N);
        if (x==2) return min((C[k+1]-C[k]+N)%N, (C[k]-C[k+1]+N)%N);
    }
}

ll DP(ll i, ll j, ll k, ll l) {
    if (i==0 && j==0 && k==0) return 0;
    if (dp[i][j][k][l]!=1e18) return dp[i][j][k][l];
    dp[i][j][k][l]=1e18-1;
    for (ll x=0; x<3; x++) {
        if (l==0 && i>=1) dp[i][j][k][l]=min(dp[i][j][k][l], DP(i-1, j, k, x)+cost(0, i-1, j, k, x));
    }
    for (ll x=0; x<3; x++) {
        if (l==1 && j>=1) dp[i][j][k][l]=min(dp[i][j][k][l], DP(i, j-1, k, x)+cost(1, i, j-1, k, x));
    }
    for (ll x=0; x<3; x++) {
        if (l==2 && k>=1) dp[i][j][k][l]=min(dp[i][j][k][l], DP(i, j, k-1, x)+cost(2, i, j, k-1, x));
    }
    return dp[i][j][k][l];
}

void solve() {
    cin >> N;
    ll a; cin >> a;
    for (ll i=1; i<=a; i++) {
        cin >> A[i]; 
        A[i]--;
    }
    ll b; cin >> b;
    for (ll i=1; i<=b; i++) {
        cin >> B[i]; 
        B[i]--; 
        B[i]=(B[i]-N/3+N)%N;
    }
    ll c; cin >> c;
    for (ll i=1; i<=c; i++) {
        cin >> C[i];
        C[i]--;
        C[i]=(C[i]+N/3)%N;
    }
    fill(&dp[0][0][0][0], &dp[a+3][b+3][c+3][5], 1e18);
    cout << min(DP(a, b, c, 0), min(DP(a, b, c, 1), DP(a, b, c, 2)));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
