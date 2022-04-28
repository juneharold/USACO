#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define f first
#define s second

int parent[1000005]={}, sz[1000005]={};

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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) {
        parent[i]=i;
        sz[i]=1;
    }
    for (int i=0; i<M; i++) {
        int x, a, b; cin >> x >> a >> b;
        if (x==0) {
            Union(a, b);
        }
        else {
            if (Find(a)==Find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
