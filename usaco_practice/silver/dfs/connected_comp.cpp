#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[1005];
int visit[1005]={};

void dfs(int cur, int k)
{
    visit[cur]=k;
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j];
        if (visit[next]==0) dfs(next, k);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;
    for (int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int k=1;
    for (int i=1; i<=N; i++)
    {
        if (visit[i]==0)
        {
            dfs(i, k);
        }
        k++;
    }
    int counter[1005]={};
    for (int i=1; i<=N; i++)
    {
        if (visit[i]!=0) 
        {
            counter[visit[i]]=1;
        }
    }
    int ans=0;
    for (int i=1; i<1005; i++)
    {
        if (counter[i]==1) ans++;
    }
    cout << ans;
}
