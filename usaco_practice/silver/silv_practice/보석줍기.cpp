#include <iostream>
#include <algorithm>
using namespace std;

long long dia[100005]={}, a[100005]={}, pfs[100005]={};

int main()
{
    long long N, M; cin >> N >> M;
    for (long long i=1; i<=N; i++) {
        cin >> dia[i];
        dia[i]*=1000;
    }

    long long lo=0, hi=2000000;
    while (lo<hi) {
        long long mid=(lo+hi)/2+1;
        for (long long i=1; i<=N; i++) a[i]=dia[i]-mid;
        for (long long i=1; i<=N; i++) pfs[i]=pfs[i-1]+a[i];

        bool possible=false;
        long long minimum=0;
        for (long long i=M; i<=N; i++) {
            if (pfs[i]>=minimum) possible=true;
            minimum=min(minimum, pfs[i-M+1]);
        }

        if (possible) lo=mid;
        else hi=mid-1;
    }
    cout << lo;
}
