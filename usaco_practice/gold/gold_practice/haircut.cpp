#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const long long MAX=1e5+5;
long long N, fw[MAX]={}, sum_inv[MAX]={};
pair<long long, long long> A[MAX];

long long query (long long p) {
    long long ret=0;
    while (p!=0) {
        ret+=fw[p];
        p-=(p&-p);
    }
    return ret;
}

void update(long long p, long long v) {
    while (p<=N) {
        fw[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    cin >> N;
    for (long long i=0; i<N; i++) {
        cin >> A[i].f;
        A[i].s=i+1;
    }
    sort(A, A+N);

    for (long long i=N-1; i>=0; i--) {
        sum_inv[A[i].f]+=query(A[i].s-1);
        update(A[i].s, 1);
    }

    long long ans=0;
    cout << 0 << "\n";
    for (long long j=1; j<=N-1; j++) {
        ans+=sum_inv[j-1];
        cout << ans << "\n";
    }
}
