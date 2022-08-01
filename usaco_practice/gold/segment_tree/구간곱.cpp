#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const int MOD=1e9+7;
ll tree[4000005]={};

ll query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 1;
    else if (qa<=a && b<=qb) return tree[n];
    int mid=(a+b)/2;
    return (query(2*n, a, mid, qa, qb)*query(2*n+1, mid+1, b, qa, qb))%MOD;
}

void update (int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    else if (qa<=a && b<=qb) {tree[n]=v; return;}
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    tree[n]=(tree[2*n]*tree[2*n+1])%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    for (int i=1; i<=N; i++) {
        int x; cin >> x;
        update(1, 1, N, i, i, x);
    }
    for (int i=1; i<=M+K; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a==1) update(1, 1, N, b, b, c);
        else cout << query(1, 1, N, b, c) << "\n";
    }
}
