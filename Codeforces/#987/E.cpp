#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e6+5, sqrmax=635, MOD=1e9+7, INF=1e18;

vector<int> graph[nmax];
int dp[nmax];

int ops(multiset<int> &ms) {
    int n=ms.size();
    if (n==0) return 0;
    int a=log2(n*2-0.1);
    return a;
}



int dfs(int cur) {
    if (dp[cur]!=-1) return dp[cur];
    if (graph[cur].size()==0) return dp[cur]=0;
    multiset<int> childs;
    for (int nx: graph[cur]) {
        dp[cur]=max(dp[cur], dfs(nx)+1);
        childs.insert(dfs(nx));
    }
    while (childs.size()>=2) {
        int a=*childs.begin();
        int b=*++childs.begin();
        childs.erase(childs.begin());
        childs.erase(childs.begin());
        childs.insert(max(a, b)+1);
    }
    dp[cur]=max(dp[cur], *childs.begin());
    return dp[cur];
}

void solve() {
    int n; cin >> n;
    int p;
    for (int i=2; i<=n; i++) {
        cin >> p;
        graph[p].push_back(i);
    }
    fill(&dp[0], &dp[n+1], -1);
    cout << dfs(1) << "\n";
    //for (int i=1; i<=n; i++) cout << dp[i] << ' ';

    for (int i=1; i<=n; i++) {
        dp[i]=0;
        graph[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}