#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N=1e5+5;
int N, K, M, visit[MAX_N];
vector<int> graph[MAX_N], hypertubes[MAX_N];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> M;
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=K; j++) {
            int a; cin >> a;
            hypertubes[i].push_back(a);
        }
        for (auto x: hypertubes[i]) {
            graph[x].push_back(i);
        }
    }

    q.push(1); visit[1]=1;

    while (!q.empty()) {
        int cur=q.front(); q.pop();
        for (auto ht: graph[cur]) {
            for (auto nx: hypertubes[ht]) {
                if (nx==cur) continue;
                if (visit[nx]==0) {
                    visit[nx]=visit[cur]+1;
                    q.push(nx);
                }
            }
        }
    }

    if (visit[N]==0) cout << -1;
    else cout << visit[N];
}
