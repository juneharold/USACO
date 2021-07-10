#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> graph[100005];
int visit[100005]={};
int days=0;

void dfs(int cur) {
    visit[cur]=1;
    int cnt=0;
    for (int j=0; j<graph[cur].size(); j++) {
        int next=graph[cur][j];
        if (visit[next]==0) cnt++;
    }
    while (visit[cur]<=cnt) {
        visit[cur]*=2;
        days++;
    }
    for (int j=0; j<graph[cur].size(); j++) {
        int next=graph[cur][j];
        if (visit[next]==0) {
            days++;
            visit[cur]-=1;
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
