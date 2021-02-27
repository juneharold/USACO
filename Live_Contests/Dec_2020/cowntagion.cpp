#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> graph[100005];
int numcows[100005]={};
int days=0;

void dfs(int cur)
{
    numcows[cur]=1;
    while (numcows[cur]<graph[cur].size())
    {
        numcows[cur]*=2;
        days++;
    }
    for (int j=0; j<graph[cur].size(); j++)
    {
        int next=graph[cur][j];
        if (numcows[next]==0) 
        {
            days++;
            numcows[cur]-=1;
            dfs(next);
        }
    }
}

int main()
{
    int N; cin >> N;
    for (int i=0; i<N-1; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << days;
}

/*
3
1 2
1 3

*/


