#include <iostream>
#include <algorithm>
using namespace std;

int n, m, p[100005]={}, sz[100005]={};

int Find(int x) {
    if (x==p[x]) return x;
    return p[x]=Find(p[x]);
}

void Union(int a, int b) {
    a=Find(a), b=Find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) swap(a, b);
    p[a]=b;
    sz[b]+=sz[a];
    n--;
}

int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        p[i]=i;
        sz[i]=1;
    }

    int maxsize=1;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        Union(a, b);
        maxsize=max(maxsize, sz[Find(a)]);
        cout << n << ' ' << maxsize << "\n";
    }
}