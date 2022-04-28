#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define f first
#define s second

int parent[200005]={}, sz[200005]={};
pair<int, int> net[200005];

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
    int T; cin >> T;
    while (T--) {
        int F, idx=1; cin >> F;
        map<string, int> m;
        for (int i=0; i<F; i++) {
            string a, b; cin >> a >> b;
            if (m.count(a)==0) {
                m[a]=idx;
                idx++;
            }
            if (m.count(b)==0) {
                m[b]=idx;
                idx++;
            }
            net[i]={m[a], m[b]};
        }

        for (int i=1; i<=200000; i++) {
            parent[i]=i;
            sz[i]=1;
        }

        for (int i=0; i<F; i++) {
            Union(net[i].f, net[i].s);
            cout << sz[Find(net[i].f)] << "\n";
        }
    }
}
