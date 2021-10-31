#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

const int MAX=2e5+5;
int N, M, parent[MAX]={}, order[MAX], open[MAX]={};
vector<int> edges[MAX];

int Find (int x) {
    if (parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}

void Union (int a, int b) {
    a=Find(a);
    b=Find(b);
    if (a==b) return;
    parent[b]=a;
}

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1; i<=N; i++) cin >> order[i];

    for (int i=1; i<=N; i++) {
        parent[i]=i;
    }

    int num_components=0;
    int ans[MAX]={};

    for (int i=N; i>=1; i--) {
        int u=order[i]; open[u]=1;
        num_components++;
        for (int j=0; j<edges[u].size(); j++) {
            int v=edges[u][j];
            if (open[v]==0) continue;

            if (Find(u)!=Find(v)) {
                Union(u, v);
                num_components--;
            }
        }

        if (num_components<=1) ans[i]=1;
        else ans[i]=0;
    }

    for (int i=1; i<=N; i++) {
        if (ans[i]==1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
