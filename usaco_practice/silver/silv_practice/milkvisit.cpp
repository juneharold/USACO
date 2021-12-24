#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX=1e5+5;
int N, M, visit[MAX]={}, component=1;
char type[MAX]={};
vector<int> graph[MAX];

void dfs(int cur, int comp) {
    visit[cur]=comp;
    for (int i=0; i<graph[cur].size(); i++) {
        int nx=graph[cur][i];
        if (visit[nx]==0) {
            if (type[cur]!=type[nx]) dfs(nx, ++component);
            else dfs(nx, comp);
        }
    }
}

int main()
{
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> type[i];
    for (int i=1; i<=N-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, component);

    //for (int i=1; i<=N; i++) cout << visit[i] << " ";

    for (int i=1; i<=M; i++) {
        int x, y; cin >> x >> y;
        char c; cin >> c;
        if (visit[x]!=visit[y]) cout << "1";
        else {
            if (type[x]==c) cout << "1";
            else cout << "0";
        }
    }

}
