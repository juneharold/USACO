#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair <int, int> > graph[10000];
int visit[10000]={};


void dfs(int cur, int K)
{
    visit[cur]=1;
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j].first;
        if (visit[next]==0 and graph[cur][j].second>=K) dfs(next, K);
    }
}

int main()
{
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int N, Q; cin >> N >> Q;
    for (int i=0; i<N-1; i++)
    {
        int p, q, r; cin >> p >> q >> r;
        graph[p].push_back(make_pair(q, r));
        graph[q].push_back(make_pair(p, r));
    }
    for (int i=0; i<Q; i++)
    {
        int K, V; cin >> K >> V;
        int MIN=1e9;
        int counter=0;
        dfs(V, K);
        for (int i=0; i<9999; i++)
        {
            if (visit[i]==1) counter++;
        }
        cout << counter-1 << "\n";
        fill(&visit[0], &visit[10000], 0);
    }
}
