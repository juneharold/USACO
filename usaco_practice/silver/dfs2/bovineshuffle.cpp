#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int counter=0;
vector <int> graph[100005];
int visit[100005]={};
vector <int> path;

void dfs(int cur)
{
    path.push_back(cur);
    visit[cur]=1;
    for (int i=0; i<graph[cur].size(); i++)
    {
        int next=graph[cur][i];

        if (visit[next]==1)
        {
            int add=0;
            for (int j=0; j<path.size(); j++)
            {
                if (path[j]==next)
                {
                    add+=path.size()-j;
                    break;
                }
            }
            counter+=add;
        }
        if (visit[next]==0)
        {
            dfs(next);
        }
        //if (visit[next]==1) counter++;
    }
}

int main()
{
    //freopen("shuffle.in", "r", stdin);
    //freopen("shuffle.out", "w", stdout);
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        int a; cin >> a;
        //if (a==i) counter++;
        graph[i].push_back(a);
    }
    for (int i=1; i<=n; i++)
    {
        if (visit[i]==0)
        {
            dfs(i);
        }
        path.clear();
    }
    cout << counter;
}
