#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
const int nmax=1e5+5;

ll A[nmax]={}, active[1000005]={};

struct query {
    int l, r, idx, bucket;
};
query q[nmax];

bool cmp(query a, query b) {
    if (a.bucket==b.bucket) return a.r<b.r;
    return a.bucket<b.bucket;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q; cin >> N >> Q;
    for (int i=1; i<=N; i++) cin >> A[i];

    int K=sqrt(N);
    for (int i=1; i<=Q; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idx=i;
        q[i].bucket=q[i].l/K;
    }
    sort(&q[1], &q[Q+1], cmp);

    ll sum=0;
    vector<ll> ans(Q+1, 0);
    for (int i=q[1].l; i<=q[1].r; i++) {
        sum-=active[A[i]]*active[A[i]]*A[i];
        active[A[i]]++;
        sum+=active[A[i]]*active[A[i]]*A[i];
    }
    ans[q[1].idx]=sum;
    int l=q[1].l, r=q[1].r;
    for (int i=2; i<=Q; i++) {
        while (q[i].l<l) {
            l--;
            sum-=active[A[l]]*active[A[l]]*A[l];
            active[A[l]]++;
            sum+=active[A[l]]*active[A[l]]*A[l];
        }
        while (r<q[i].r) {
            r++;
            sum-=active[A[r]]*active[A[r]]*A[r];
            active[A[r]]++;
            sum+=active[A[r]]*active[A[r]]*A[r];
        }
        while (l<q[i].l) {
            sum-=active[A[l]]*active[A[l]]*A[l];
            active[A[l]]--;
            sum+=active[A[l]]*active[A[l]]*A[l];
            l++;
        }
        while (q[i].r<r) {
            sum-=active[A[r]]*active[A[r]]*A[r];
            active[A[r]]--;
            sum+=active[A[r]]*active[A[r]]*A[r];
            r--;
        }
        ans[q[i].idx]=sum;
    }

    for (int i=1; i<=Q; i++) cout << ans[i] << "\n";
}
