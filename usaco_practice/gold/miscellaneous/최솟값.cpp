#include <iostream>
#include <algorithm>
using namespace std;

int segtree[400005]={};

void update(int nn, int a, int b, int qa, int qb, int v) { //qa부터 qb를 v로 업데이트
    if (qa<=a && b<=qb) {
        segtree[nn]=v;
        return;
    }
    if (qb<a || b<qa) return;
    int mid=(a+b)/2;
    update(2*nn, a, mid, qa, qb, v);
    update(2*nn+1, mid+1, b, qa, qb, v);
    segtree[nn]=min(segtree[2*nn], segtree[2*nn+1]);
}

int query(int nn, int a, int b, int qa, int qb) {
    if (qa<=a && b<=qb) return segtree[nn];
    if (qb<a || b<qa) return 1e9;
    int mid=(a+b)/2;
    int res1=query(2*nn, a, mid, qa, qb);
    int res2=query(2*nn+1, mid+1, b, qa, qb);
    return min(res1, res2);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(&segtree[0], &segtree[400001], 1e9);
    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++) {
        int a; cin >> a;
        update(1, 1, N, i, i, a);
    }
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        cout << query(1, 1, N, a, b) << "\n";
    }
}