#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

int dp[200005]={};
vector<pair<int, int>> graph[200005];
set<int> cut;
bool possible=true;

int dfs(int cur, int p) {
    if (dp[cur]!=-1) return dp[cur];
    dp[cur]=1; //본인 
    int cnt1=0, cnt2=0, i_to_p=-1;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i].f;
        if (nx==p) {
            i_to_p=graph[cur][i].s;
            continue;
        }
        dp[cur]+=dfs(nx, cur);
        if (dfs(nx, cur)==1) cnt1++;
        if (dfs(nx, cur)==2) cnt2++;
    }
    if (cnt2>1) possible=false;
    if (cnt1>2) possible=false;
    if (cnt2==1 && cnt1>0) possible=false;
    dp[cur]%=3;
    if (dp[cur]==0) cut.insert(i_to_p);
    
    return dp[cur];
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i=1; i<=n-1; i++) {
            int u, v; cin >> u >> v;
            graph[u].push_back(make_pair(v, i));
            graph[v].push_back(make_pair(u, i));
        }
        fill(&dp[0], &dp[n+1], -1);

        dfs(1, 0);

        if (!possible || n%3!=0) {
            cout << "-1\n";
        }
        else {
            cout << cut.size()-1 << "\n";
            for (int edge: cut) if (edge!=-1) cout << edge << ' ';
            cout << "\n";
        }

        // initialize 
        for (int i=0; i<=n; i++) {
            graph[i].clear();
            dp[i]=0;
        }
        cut.clear();
        possible=true;
    }
}

/*
1
9
1 2
4 3
7 9
5 4
4 6
3 2
8 7
1 7
*/