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

int a[305]={}, dp[305][305]={};

int DP(int i, int j) {
    if (i>=j) return 0;
    if (dp[i][j]!=-1) return dp[i][j];

    dp[i][j]=DP(i+1, j-1)+(a[i]==a[j]);
    for (int k=i; k<=j; k++) dp[i][j]=max(dp[i][j], DP(i, k)+DP(k, j));

    return dp[i][j];
}

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    fill(&dp[0][0], &dp[N+1][N+1], -1);
    cout << N-DP(1, N) << "\n";
}
