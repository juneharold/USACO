#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> graph[20005];
int visit[20005];
int check=1;

void dfs(int cur, int k)
{
    visit[cur]=k;
    //cout << cur << " " << k << "\n";
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j];
        if (visit[next]==k)
        {
            check=0;
            //cout << "here\n";
            break;
        }
        if (visit[next]==0) dfs(next, 3-k);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K; cin >> K;
    for (int t=0; t<K; t++)
    {
        int V, E; cin >> V >> E;
        for (int i=0; i<E; i++)
        {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int k=1;
        for (int i=1; i<=V; i++)
        {
            if (check==0) break;
            if (visit[i]==0) dfs(i, k);
        }
        if (check==0) cout << "NO\n";
        else cout << "YES\n";
        for (int i=0; i<20005; i++) graph[i].clear();
        fill(&visit[0], &visit[20005], 0);
        check=1;
    }
}

/*
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
*/
