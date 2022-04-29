#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define f first
#define s second

int N, p[100005]={}, sz[100005]={};
int Find(int x) {
    if (p[x]==x) return x;
    else return p[x]=Find(p[x]);
}
void Union(int a, int b) {
    int A=Find(a), B=Find(b);
    if (A==B) return;
    if (sz[A]>sz[B]) swap(A, B);
    p[A]=B;
    sz[B]+=sz[A];
}

pair<int, int> X[100005], Y[100005], Z[100005];
pair<int, pair<int, int>> edge[300005];
int idx=1;
void preprocessing() {
    sort(&X[1], &X[N+1]);
    sort(&Y[1], &Y[N+1]);
    sort(&Z[1], &Z[N+1]);
    for (int i=1; i<N; i++) {
        edge[idx]={abs(X[i].f-X[i+1].f), {X[i].s, X[i+1].s}};
        idx++;
    }
    for (int i=1; i<N; i++) {
        edge[idx]={abs(Y[i].f-Y[i+1].f), {Y[i].s, Y[i+1].s}};
        idx++;
    }
    for (int i=1; i<N; i++) {
        edge[idx]={abs(Z[i].f-Z[i+1].f), {Z[i].s, Z[i+1].s}};
        idx++;
    }
    sort(&edge[1], &edge[idx]);
}

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) {
        int x, y, z; cin >> x >> y >> z;
        X[i]={x, i};
        Y[i]={y, i};
        Z[i]={z, i};
    }
    preprocessing();

    for (int i=1; i<=100000; i++) {
        p[i]=i;
        sz[i]=1;
    }

    long long ans=0;
    for (int i=1; i<idx; i++) {
        int a=edge[i].s.f, b=edge[i].s.s;
        if (Find(a)!=Find(b)) {
            Union(a, b);
            ans+=edge[i].f;
        }
    }

    cout << ans;
}
