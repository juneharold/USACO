#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N=1e5+5, MAX_M=2e5+5;
int visit[MAX_N]={}, h[MAX_N]={};
vector<pair<int, int>> edge[MAX_M];
priority_queue<pair<int, int>> pq;
int N, M, D, E;

int main()
{
    cin >> N >> M >> D >> E;
    for (int i=1; i<=N; i++) cin >> h[i];
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    
}
