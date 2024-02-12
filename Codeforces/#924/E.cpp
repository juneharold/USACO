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
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;
 
vector<int> val[2005], cost[2005];
 
void solve() {
    ll n, x, y, s; cin >> n >> x >> y >> s;
    if (s<(n-1)*(x%y)+x || s>(2*x+(n-1)*y)*n/2 || (s-(x%y)*n)%y!=0) {
        cout <<  "NO\n";
        return;
    }
    ll K=(s-(x%y)*n)/y;

    vector<vector<int>> dp(2, vector<int>(K+1, 1e9));
    vector<pii> from(K+1, {-1, -1});
    dp[0][0]=0;
    for (int i=1; i<=sqrmax; i++) {
        for (int j=0; j<=K; j++) {
            dp[i%2][j]=dp[(i+1)%2][j];
            for (int k=0; k<val[i].size(); k++) {
                if (j-val[i][k]>=0 && dp[(i+1)%2][j-val[i][k]]+cost[i][k]<dp[i%2][j]) {
                    dp[i%2][j]=dp[(i+1)%2][j-val[i][k]]+cost[i][k];
                    from[j]={i, k};
                }
            }
        }
        for (int j=0; j<=K; j++) dp[(i+1)%2][j]=1e9;
    }
 
    for (int i=1; i<=n; i++) {
        ll target=K-(2*(x/y)+(i-1))*i/2;
        if (target>=0 && dp[sqrmax%2][target]<=n-i) {
            vector<int> ans(n+1, 0);
            for (int j=1; j<=i; j++) ans[j]=(x/y)+j-1;
            int idx=i+1;
            while (target) {
                for (int j=1; j<=(1<<from[target].sc); j++) {
                    for (int k=0; k<=from[target].fs; k++) {
                        ans[idx]=k;
                        idx++;
                    }
                }
                target-=val[from[target].fs][from[target].sc];
            }
 
            cout << "YES\n";
            for (int j=1; j<=n; j++) cout << ans[j]*y+x%y << ' ';
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main()
{
    for (int i=1; i<=sqrmax; i++) {
        int v=i*(i+1)/2, c=i+1;
        val[i].push_back(v);
        cost[i].push_back(c);
        while (val[i].back()*2<=nmax) {
            v=val[i].back()*2, c=cost[i].back()*2;
            val[i].push_back(v);
            cost[i].push_back(c);
        }
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
 
/*
x x%y x%y ... 
 
s >= (n-1)*(x%y)+x
s <= (2*x+(n-1)*y)*n/2
 
s-(x%y)*n has to be a multiple of y 
 
y * k == s-(x%y)*n
 
start with b[1]=floor(x/y)
b[i+1]=b[i]+1 or 0 
sum of b[i] has to be k 
1 0 1 0 1 0 ... 
1 2 0 1 0 1 to make 5
1 2 3 to make 6 
how many to make k? 
greedily form b[i]?
 
0 1 2 3 0 1 2 3
0 1 2 3 4 0 1 0 1 
 
knapsack dp? 
value = n*(n+1)/2, cost=n+1 
value 종류는 약 2000개 갯수는 무한
tie item in 2^N cost 2^N around 20 item per 
dp[i][j]=item i 까지 합 j 만들 수 있는 최소 cost 
dp[i][j]=dp[i-1][j]
dp[i][j]=dp[i-1][j-val[k]]+cost[k]
*/