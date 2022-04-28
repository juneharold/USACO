#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[205]={}, sz[205]={};

int Find(int x) {
    if (parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}

void Union(int a, int b) {
    int A=Find(a), B=Find(b);
    if (A==B) return;
    if (sz[A]>sz[B]) swap(A, B);
    parent[A]=B;
    sz[B]+=sz[A];
}

int main()
{
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) {
        parent[i]=i;
        sz[i]=1;
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int x; cin >> x;
            if (x==1) Union(i, j);
        }
    }

    int start=0; cin >> start;
    bool yes=true;
    for (int i=2; i<=M; i++) {
        int x; cin >> x;
        if (Find(x)!=Find(start)) yes=false;
    }
    if (yes) cout << "YES";
    else cout << "NO";
}
