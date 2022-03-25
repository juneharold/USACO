#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

int N, inpt[505][505]={}, reach[505][505]={};
vector<int> graph[505];

void dfs(int cur, int start) {
    reach[cur][start]=1;

    for (int nx: graph[cur]) {
        if (reach[nx][start]==0) dfs(nx, start);
    }
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        bool x=true;
        for (int j=1; j<=N; j++) {
            cin >> inpt[i][j];
            if (x) graph[i].push_back(inpt[i][j]);
            if (inpt[i][j]==i) x=false;
        }
    }

    for (int i=1; i<=N; i++) {
        dfs(i, i);
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        if (reach[i][inpt[i][j]]==1) {
            cout << inpt[i][j] << "\n";
            break;
        }
    }
}
