#include <iostream>
#include <vector>
using namespace std;

const int MAX=2e5+5;
int N, Q, boss[MAX][22], depth[MAX];
vector<int> tree[MAX];

void dfs (int cur, int p, int d) {
    depth[cur]=d;
    boss[cur][0]=p;

    for (int i=0; i<tree[cur].size(); i++) {
        int nx=tree[cur][i];
        if (nx!=p) dfs(nx, cur, d+1);
    }
}

int LCA (int a, int b) {
    if (depth[a]<depth[b]) swap(a, b); // a is higher location;

    for (int i=20; i>=0; i--) {
        int nx=boss[a][i];
        if (depth[nx]>=depth[b]) a=nx;
    }

    if (a==b) return a;

    for (int i=20; i>=0; i--) {
        int aa=boss[a][i], bb=boss[b][i];
        if (aa!=bb) {
            a=aa;
            b=bb;
        }
    }
    return boss[a][0];
}

int main()
{
    cin >> N >> Q;
    for (int i=2; i<=N; i++) {
        int v; cin >> v;
        tree[i].push_back(v);
        tree[v].push_back(i);
    }

    dfs(1, 0, 1);

    for (int i=1; i<=N; i++) for (int j=1; j<=20; j++) boss[i][j]=boss[boss[i][j-1]][j-1];

    for (int i=1; i<=Q; i++) {
        int a, b; cin >> a >> b;
        cout << LCA(a, b) << "\n";
    }
}
