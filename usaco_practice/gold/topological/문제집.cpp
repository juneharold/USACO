#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int in[32005]={};
vector<int> graph[32005];

int main()
{
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        in[b]++;
        graph[a].push_back(b);
    }

    priority_queue<int> pq;
    vector<int> ans;
    for (int i=1; i<=N; i++) {
        if (in[i]==0) pq.push(-i);
    }

    while (!pq.empty()) {
        int cur=-pq.top();
        pq.pop();
        ans.push_back(cur);
        for (int nx: graph[cur]) {
            in[nx]--;
            if (in[nx]==0) pq.push(-nx);
        }
    }

    for (int x: ans) cout << x << " ";
}
