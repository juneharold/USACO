#include <iostream>
using namespace std;

int tree[4000000]={};

void update(int n, int a, int b, int qa, int qb, int k) {
    if (qa<=a && b<=qb) {tree[n]+=k; return;}
    if (b<qa || qb<a) return;
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, k);
    update(2*n+1, mid+1, b, qa, qb, k);
    tree[n]=tree[2*n]+tree[2*n+1];
}

int solve(int n, int a, int b, int target) {
    if (a==b) return a;
    int mid=(a+b)/2;
    if (target<=tree[2*n]) {
        return solve(2*n, a, mid, target);
    }
    else if (tree[2*n]<target) {
        return solve(2*n+1, mid+1, b, target-tree[2*n]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        int A, B, C; cin >> A;
        if (A==1) {
            cin >> B;
            int ans=solve(1, 1, 1000000, B);
            cout << ans << "\n";
            update(1, 1, 1000000, ans, ans, -1);
        }
        else {
            cin >> B >> C;
            update(1, 1, 1000000, B, B, C);
        }
    }
}
