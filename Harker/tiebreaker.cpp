#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
const int MAX=1e5+5;

int type[MAX]={}, visit[MAX]={};
vector<int> graph[MAX];
bool solved=false;

void dfs(int cur, int goal, int find, int cnt) {
    visit[cur]=1;

    if (cur==goal) {
        cout << cnt << "\n";
        solved=true;
        return;
    }
    for (auto nx: graph[cur]) {
        if (visit[nx]==1) continue;
        if (type[nx]==find) dfs(nx, goal, find, cnt+1);
        else dfs(nx, goal, find, cnt);

        if (solved) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q; cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> type[i];
    for (int i=1; i<=N-1; i++) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<=Q; i++) {
        int x; cin >> x;
        if (x==1) {
            int a, b; cin >> a >> b;
            type[a]=b;
        }
        else {
            int a, b, c; cin >> a >> b >> c;
            if (type[a]==c) dfs(a, b, c, 1);
            else dfs(a, b, c, 0);
            solved=false;
            if (i!=Q) fill(&visit[1], &visit[N+1], 0);
        }
    }
}

/*
5 5
3 3 3 3 3
1 2
1 3
3 4
3 5
2 1 5 3
2 2 5 3
1 1 1
1 2 1
2 2 5 1
정답:
3
4
2

11 8
4 3 3 2 4 1 1 2 4 4 3
1 2
2 7
1 3
3 4
4 5
3 6
6 11
6 8
8 9
8 10
2 7 9 1
2 7 9 2
2 7 9 3
2 1 10 4
1 6 2
2 5 11 2
1 3 2
2 4 9 2

정답:
2
1
2
2
2
4
*/
