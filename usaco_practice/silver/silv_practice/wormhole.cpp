#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pos[100005]={};
struct wormhole
{
    int a, b, w;
};
wormhole WH[100005]={};

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
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) 
    {
        cin >> pos[i];
        if (pos[i]==i) need[i]=1;
    }
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
    for (int i=0; i<M; i++) 
    {
        int a, b, w; cin >> a >> b >> w;
        WH[i]= {a, b, w};
    }
    int low=0, high=1e6;
    while (low < high)
    {
        int mid=(low+high)/2+1;
        int have[100005]={};
        for (int i=1; i<=N; i++) have[i]=need[i];
        for (int i=0; i<M; i++) 
        {
            if (WH[i].w>=mid)
            {
                have[WH[i].a]=1;
                have[WH[i].b]=1;
            }
        }
        int indicator=0;
        for (int i=1; i<=N; i++)
        {
            if (have[i]==0) indicator=1;
        }
        if (indicator==0) low=mid;
        else high=mid-1;
    }
    cout << low;
}

