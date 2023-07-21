#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
#define f first
#define s second

int N, X[300005], T[300005], C[300005];
ll st[12000005]={};
map<int, int> m;

ll query(int n, int a, int b, int qa, int qb) {
    if (b<qa || qb<a) return -1e9;
    if (qa<=a && b<=qb) return st[n];
    int mid=(a+b)/2;
    return max(query(2*n, a, mid, qa, qb), query(2*n+1, mid+1, b, qa, qb));
}

void update(int n, int a, int b, int qa, int qb, ll v) {
    if (b<qa || qb<a) return;
    if (qa<=a && b<=qb) {st[n]=max(st[n], v); return;}
    int mid=(a+b)/2;
    update(2*n, a, mid, qa, qb, v);
    update(2*n+1, mid+1, b, qa, qb, v);
    st[n]=max(st[2*n], st[2*n+1]);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<pair<int, int>> v;
    for (int i=1; i<=N; i++) {
        cin >> X[i] >> T[i] >> C[i];
        v.push_back({T[i]-X[i], i});
    }
    sort(v.begin(), v.end());
    int idx=0;
    for (int i=0; i<N; i++) {
        if (i>0 && v[i].f==v[i-1].f) m[v[i].f]=idx;
        else m[v[i].f]=++idx;
    }
    
    ll ans=0;
    for (int i=1; i<=N; i++) {
        ll temp=query(1, 1, N, 1, m[T[i]-X[i]])+C[i];
        ans=max(ans, temp);
        update(1, 1, N, m[T[i]-X[i]], m[T[i]-X[i]], temp);
    }
    cout << ans;
}