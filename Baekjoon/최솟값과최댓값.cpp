#include <iostream>
#include <algorithm>
using namespace std;

int mintree[400005]={}, maxtree[400005]={};

void update(int n, int a, int b, int qa, int qb, int v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) {
        mintree[n]=min(mintree[n], v);
        maxtree[n]=max(maxtree[n], v);
        return;
    }
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    mintree[n]=min(mintree[n], min(mintree[2*n], mintree[2*n+1]));
    maxtree[n]=max(maxtree[n], max(maxtree[2*n], maxtree[2*n+1]));
}

int find_min(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 2e9;
    if (qa<=a && b<=qb) return mintree[n];
    int mid=(a+b)/2;
    return min(find_min(2*n, a, mid, qa, qb), find_min(2*n+1, mid+1, b, qa, qb));
}

int find_max(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return 0;
    if (qa<=a && b<=qb) return maxtree[n];
    int mid=(a+b)/2;
    return max(find_max(2*n, a, mid, qa, qb), find_max(2*n+1, mid+1, b, qa, qb));
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    fill(&mintree[0], &mintree[4*N], 2e9);
    for (int i=1; i<=N; i++) {
        int x; cin >> x;
        update(1, 1, N, i, i, x);
    }
    for (int i=1; i<=M; i++) {
        int a, b; cin >> a >> b;
        cout << find_min(1, 1, N, a, b) << ' ' << find_max(1, 1, N, a, b) << "\n";
    }
}