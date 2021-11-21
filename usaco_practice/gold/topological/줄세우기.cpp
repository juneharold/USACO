#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> adj[32005];
int N, M, in[32005]={};
queue<int> q;

int main()
{
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        in[b]++;
        adj[a].push_back(b);
    }

    for (int i=1; i<=N; i++) {
        if (in[i]==0) q.push(i);
    }

    while (!q.empty()) {
        int cur=q.front();

        for (int i=0; i<adj[cur].size(); i++) {
            int nx=adj[cur][i];
            in[nx]--;
            if (in[nx]==0) {
                q.push(nx);
            }
        }

        cout << cur << " ";
        q.pop();
    }
}
