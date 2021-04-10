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
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int c=0; c<t; c++)
    {
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
        cout << n-counter << "\n";
        for (int i=1; i<=n; i++)
        {
            graph[i].clear();
            visit[i]=0;
        }
        path.clear();
        counter=0;
    }
}

/*
2
7
3 1 3 7 3 4 6
8
1 2 3 4 5 6 7 8
*/
