#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, a_cnt[10005]={}, b_cnt[10005]={}, pfs[10005]={}, ans[10005]={};

int main()
{
    cin >> N >> M;
    for (long long i=0; i<N; i++) {
        long long a, b; cin >> a >> b;
        a_cnt[a]++; b_cnt[b]++;
    }

    for (long long i=0; i<=2*M; i++) {
        long long temp=0;
        for (long long j=i; j>=0; j--) temp+=a_cnt[j]*a_cnt[i-j];
        pfs[i]+=temp;
    }

    for (long long i=0; i<=2*M; i++) {
        long long temp=0;
        for (long long j=i; j>=0; j--) temp+=b_cnt[j]*b_cnt[i-j];
        pfs[i+1]-=temp;
    }

    long long ans=0;
    for (long long i=0; i<=2*M; i++) {
        ans+=pfs[i];
        cout << ans << "\n";
    }
}
