#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX=1e5+5;
int N, M, C, in[MAX]={}, ans[MAX];
vector<pair<int, int>> graph[MAX];
queue<pair<int, int>> q;

int main()
{
    cin >> N >> M >> C;
    for (int i=1; i<=N; i++) cin >> ans[i];
    for (int i=1; i<=C; i++) {
        int a, b, x; cin >> a >> b >> x;
        graph[a].push_back({b, x});
        in[b]++;
    }

    for (int i=1; i<=N; i++) {
        if (in[i]==0) q.push({i, ans[i]});
    }

    while (!q.empty()) {
        int cur=q.front().first, day=q.front().second;
        q.pop();

        for (int i=0; i<graph[cur].size(); i++) {
            int nx=graph[cur][i].first, w=graph[cur][i].second;

            ans[nx]=max(ans[nx], day+w);
            in[nx]--;

            if (in[nx]==0) q.push({nx, ans[nx]});
        }
    }

    for (int i=1; i<=N; i++) cout << ans[i] << "\n";
}
