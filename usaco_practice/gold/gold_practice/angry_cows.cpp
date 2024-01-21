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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=5e4+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int x[nmax]={}, dp[nmax][2]={};

void solve() {
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> x[i];
        x[i]*=2;
    }
    sort(&x[1], &x[N+1]);

    fill(&dp[0][0], &dp[N+2][1], 2e9);
    dp[1][0]=dp[N][1]=-2;
    int idx=1;
    for (int i=2; i<=N; i++) {
        while (idx+1<i && x[i]-x[idx+1]>dp[idx+1][0]+2) {
            idx++;
        }
        dp[i][0]=min(x[i]-x[idx], dp[idx+1][0]+2);
    }
    idx=N;
    for (int i=N-1; i>=1; i--) {
        while (idx-1>i && x[idx-1]-x[i]>dp[idx-1][1]+2) {
            idx--;
        }
        dp[i][1]=min(x[idx]-x[i], dp[idx-1][1]+2);
    }
    
    ll lo=0, hi=1e12;
    while (lo<hi) {
        ll R=(lo+hi)/2;
        //cout << "R: " << R << endl;
        bool possible=false;
        int i=1, j=1; //sliding window
        while (i<=j && j<=N) {
            if (x[j]-x[i]<=2*R && dp[i][0]<=R-2 && dp[j][1]<=R-2) {
                possible=true;
                break;
            }
            if (j<N && x[j+1]-x[i]<=2*R) j++;
            else if (i<j) i++;
            else i++, j++;
        }
        if (possible) hi=R;
        else lo=R+1;
    }
    cout << fixed << setprecision(1) << lo/2.0;
}

int main()
{
    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
