#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector < pair<int, int> > graph[100005];
int visit[100005]={};

void dfs(int cur, int mid)
{
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++)
    {
        int next = graph[cur][i].first;
        int next_weight = graph[cur][i].second;
        if (visit[next]==0 and mid<=next_weight)
        {
            dfs(next, mid);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    for (int i=1; i<=M; i++)
    {
        int a, b, weight; cin >> a >> b >> weight;
        graph[a].push_back(make_pair(b, weight));
        graph[b].push_back(make_pair(a, weight));
    }
    int from, to; cin >> from >> to;
    int low=0, high=1e9;
    while (low<high)
    {
        int mid=(low+high)/2+1;
        dfs(from, mid);
        if (visit[to]==1) low=mid;
        else high=mid-1;
        fill(visit, visit+100005, 0);
    }
    cout << low;
}




