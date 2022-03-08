#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

long long n, energy[100005]={}, visit[100005]={}, need[100005]={}, ans[100005]={};
vector<pair<long long, long long>> graph[100005];
vector<long long> path;

void dfs(long long cur) {
    visit[cur]=1;
    path.push_back(cur);

    //binary search here
    long long lo=0, hi=path.size()-1;
    while (lo<hi) {
        long long mid=(lo+hi)/2;
        if (need[cur]-need[path[mid]]<=energy[cur]) hi=mid;
        else lo=mid+1;
    }
    ans[cur]=path[lo];

    for (long long i=0; i<graph[cur].size(); i++) {
        long long nx=graph[cur][i].f, w=graph[cur][i].s;
        if (visit[nx]==0) {
            need[nx]=need[cur]+w;
            dfs(nx);
        }
    }
    path.erase(--path.end());
}

int main()
{
    cin >> n;
    for (long long i=1; i<=n; i++) cin >> energy[i];
    for (long long i=1; i<=n-1; i++) {
        long long a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(1);

    for (long long i=1; i<=n; i++) cout << ans[i] << "\n";
}

/*
4
10
8
22
18
1 2 10
2 3 10
2 4 10

12
100000
10000
10000
100000
10000
10000
100000
100000
100000
10000
10000
10000
1 2 10000
2 3 10000
4 2 10000
9 4 10000
9 12 10000
1 5 10000
5 6 10000
7 5 10000
5 8 10000
7 10 10000
11 7 10000
*/
