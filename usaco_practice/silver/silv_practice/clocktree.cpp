#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX=2505;

int N, initial[MAX]={}, visit[MAX]={}, nodes_checked=0, ans=0;
vector<int> tree[MAX];
bool possible=false;

void dfs(int cur, int p) {
    if (p!=0) visit[cur]=(visit[cur]+1)%12;
    //if (visit[cur]>12) visit[cur]-=12;

    for (auto nx: tree[cur]) {
        if (nx==p) continue;
        dfs(nx, cur);
    }

    int need=12-visit[cur];
    visit[cur]=12; visit[p]=(visit[p]+need+1)%12;
    //if (visit[p]>12) visit[p]-=12;
    nodes_checked+=1;

    if (nodes_checked==N-1 && (visit[p]==1 || visit[p]==0)) {
        possible=true;
    }
}

int main()
{
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);

    cin >> N;
    for (int i=1; i<=N; i++) cin >> initial[i];
    for (int i=1; i<=N-1; i++) {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) visit[j]=initial[j];
        nodes_checked=0; possible=false;

        dfs(i, 0);

        if (possible==true) ans++;
    }
    cout << ans;
}
