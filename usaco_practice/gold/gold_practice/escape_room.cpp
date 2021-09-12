#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second

const int MAX=1e6+10, MAX_N=1005;
int M, N, visit[MAX_N][MAX_N]={};
vector<pair<int,int>> vertex[MAX];
queue<int> q;

int main()
{
    cin >> M >> N;
    for (int i=1; i<=M; i++) for (int j=1; j<=N; j++) {
        int x; cin >> x;
        vertex[x].push_back({i, j});
    }

    q.push(M*N);
    visit[M][N]=1;

    while(!q.empty()) {
        int X=q.front();
        //cout << cur << "\n";
        q.pop();
        for (auto nx: vertex[X]) {
            if (visit[nx.f][nx.s]==0) {
                visit[nx.f][nx.s]=1;
                q.push(nx.f*nx.s);
            }
        }
    }

    if (visit[1][1]==1) cout << "yes";
    else cout << "no";
}
