#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll A[200005]={}, pfs1[200005]={}, pfs2[200005]={};

/*
pfs1=A1-A2+A3-A4+...
pfs2=A1-2*A2+3*A3-4*A4+...
*/

void update(int N, int Q) {
    for (int i=1; i<=N; i++) {
        if (i%2==0) pfs1[i]=pfs1[i-1]-A[i];
        else pfs1[i]=pfs1[i-1]+A[i];
        if (i%2==0) pfs2[i]=pfs2[i-1]-i*A[i];
        else pfs2[i]=pfs2[i-1]+i*A[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, Q; cin >> N >> Q;
        for (int i=1; i<=N; i++) cin >> A[i];
        update(N, Q);

        ll ans=0;
        for (int i=1; i<=Q; i++) {
            char type; cin >> type;
            if (type=='U') {
                int x, v; cin >> x >> v;
                A[x]=v;
                update(N, Q);
            }
            else {
                int l, r; cin >> l >> r;
                if (l%2==0) {
                    ans+=-(pfs2[r]-pfs2[l-1])+(l-1)*(pfs1[r]-pfs1[l-1]);
                }
                else {
                    ans+=(pfs2[r]-pfs2[l-1])-(l-1)*(pfs1[r]-pfs1[l-1]);
                }
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
