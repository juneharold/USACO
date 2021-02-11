#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[105];
int visit[105]={};

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
    int ans=0;
    for (int i=0; i<105; i++)
    {
        if (visit[i]==1) ans++;
    }
    cout << ans-1;
    return 0;
}
