#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define ll long long
#define f first
#define s second

int N, p[250005]={}, sz[250005]={}, di[4]={0, 0, 1, -1}, dj[4]={1, -1, 0, 0};
ll grid[505][505]={};

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
}

int main()
{
    cin >> N; 
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin >> grid[i][j];
    
    vector<pair<int, pair<int, int> > > edges;
    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        for (int k=0; k<4; k++) {
            int ni=i+di[k], nj=j+dj[k];
            if (ni<1 || ni>N || nj<1 || nj>N) continue;
            edges.push_back(make_pair(abs(grid[i][j]-grid[ni][nj]), make_pair((i-1)*N+j, (ni-1)*N+nj)));
        }
    }

    for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
        p[(i-1)*N+j]=(i-1)*N+j;
        sz[(i-1)*N+j]=1;
    }

    sort(edges.begin(), edges.end());
    for (int i=0; i<edges.size(); i++) {
        pair<int, pair<int, int> > edge=edges[i];
        Union(edge.s.f, edge.s.s);
        if (sz[Find(edge.s.f)]>=(N*N+1)/2) {
            cout << edge.f;
            return 0;
        }
    }
}