#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=1e5+5;

int N, dp[nmax]={};
vector<int> graph[nmax];
bool possible=false;

void dfs(int cur, int p, int k) {
    map<int, int> exists;
    int cnt=0;
    for (int nx: graph[cur]) {
        if (nx==p) continue;
        dfs(nx, cur, k);
        if (dp[nx]+1==k) continue;
        int target=k-(dp[nx]+1);
        if (exists.find(target)!=exists.end() && exists[target]>0) exists[target]--, cnt--, dp[cur]-=target;
        else exists[dp[nx]+1]++, cnt++, dp[cur]+=dp[nx]+1;
    }
    if (cnt>1) possible=false;
}

string check_k(int k) {
    fill(&dp[1], &dp[N+1], 0);
    possible=true;
    dfs(1, 0, k);
    if (possible && dp[1]==0) return "1";
    return "0";
}

void solve() {
    cin >> N;
    for (int i=1; i<=N-1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    string ans="";
    for (int i=1; i<=N-1; i++) {
        if ((N-1)%i==0) ans+=check_k(i);
        else ans+="0";
    }
    cout << ans;
}

/*
9
1 2
2 3
3 4
4 5
5 6
2 8
8 9
1 7

*/

int main()
{
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; //cin >> T;
    while (T--) {
        solve();
    }
}
