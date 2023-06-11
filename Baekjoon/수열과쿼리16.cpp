#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A[100005]={};
pair<int, int> st[400005]={};

pair<int, int> query(int n, int a, int b, int qa, int qb) {
    if (qa<=a && b<=qb) return st[n];
    if (b<qa || qb<a) return make_pair(2e9, -1);
    int mid=(a+b)/2;
    return min(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}

void update(int n, int a, int b, int qa, int qb, pair<int, int> v) {
    if (qa<=a && b<=qb) {st[n]=v; return;}
    if (b<qa || qb<a) return;
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v); 
    update(2*n+1, mid+1, b, qa, qb, v);
    st[n]=min(st[2*n], st[2*n+1]);
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
        update(1, 1, N, i, i, make_pair(A[i], i));
    }
    int M; cin >> M;
    for (int i=1; i<=M; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a==1) {
            update(1, 1, N, b, b, make_pair(c, b));
        }
        else {
            cout << query(1, 1, N, b, c).second << "\n";
        }
    }
}