#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int vst[50005]={}, p[50005]={}, sz[50005]={}, K[250005]={}, L[250005]={};
set<int> graph[50005];
vector<int> path;
bool success=true;
char c[250005];

int Find(int x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}

void Union(int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    p[a]=b;
    sz[b]+=a;
}

void dfs(int cur) {
    vst[Find(cur)]=1;
    path.push_back(Find(cur));
    for (int nx: graph[Find(cur)]) {
        if (vst[Find(nx)]==1) {
            int idx=-1;
            for (int i=0; i<path.size(); i++) {
                if (path[i]==Find(nx)) idx=i;
            }
            if (idx!=-1) success=false;
        }
        else dfs(Find(nx));
    }
}

int main()
{
    int N, M; cin >> N >> M;
    for (int i=0; i<M; i++) cin >> K[i] >> c[i] >> L[i];

    for (int i=0; i<N; i++) {
        sz[i]=1;
        p[i]=i;
    }
    for (int i=0; i<M; i++) {
        if (c[i]=='=') Union(K[i], L[i]);
    }
    for (int i=0; i<M; i++) {
        if (c[i]!='=') {
            graph[Find(K[i])].insert(Find(L[i]));
        }
    }

    for (int i=0; i<N; i++) {
        if(vst[Find(i)]==0) dfs(Find(i));
        path.clear();
    }

    if (success) cout << "consistent";
    else cout << "inconsistent";
}
/*
4 3
1 = 2
2 = 3
1 > 3

2 2
1 > 0 
0 > 1
*/


