#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[255];
int visit[255]={};

void dfs(int cur)
{
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if (visit[next]==0)
        {
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    int cnt=0;
    for (int i=1; i<=N; i++)
    {
        if (visit[i]==0) cout << i << "\n";
        else cnt++;
    }
    if (cnt==N) cout << 0;
}
