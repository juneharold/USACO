#include <iostream>
using namespace std;

int p[1005]={}, sz[1005]={};

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

int main()
{
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        for (int i=1; i<=1000; i++) {
            p[i]=i;
            sz[i]=1;
        }

        int ans=0;
        for (int i=1; i<=M; i++) {
            int a, b; cin >> a >> b;
            if (Find(a)!=Find(b)) {
                ans++;
                Union(a, b);
            }
        }
        cout << ans << "\n";
    }
}
