#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector < pair<int, int> > graph[100005];
int visit[100005]={};
int pos[100005]={};

void dfs(int cur, int mid)
{
    visit[cur]=1;
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j].first;
        if (visit[next]==0 and graph[cur][j].second>=mid) dfs(next, mid);
    }
}

int main()
{
    //freopen("wormsort.in", "r", stdin);
    //freopen("wormsort.out", "w", stdout);
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) 
    {
        cin >> pos[i];
    }
    // seeing if all are in order
    int indic=1;
    for (int i=1; i<=N; i++) 
    {
        if (pos[i]!=i) indic=0;
    }
    if (indic==1) 
    {
        cout << -1;
        return 0;
    }
    // taking in input
    for (int i=0; i<M; i++) 
    {
        int a, b, w; cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
        graph[b].push_back(make_pair(a, w));
    }
    int low=0, high=1000000;
    while (low<high)
    {
        int mid=(low+high)/2+1;
        int indicator=1;
        for (int i=1; i<=N; i++)
        {  
            dfs(pos[i], mid); 
            if (visit[pos[i]]!=1) 
            {
                indicator=0;
            }
        }
        fill(&visit[0], &visit[100005], 0);
        if (indicator==0) low=mid;
        else high=mid-1;
    }
    cout << low;
}

/*
4 3 
4 2 1 3
1 2 1
3 4 2 
1 3 100
*/


