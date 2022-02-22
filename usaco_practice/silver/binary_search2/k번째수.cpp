#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main()
{
    ll N, K; cin >> N >> K;

    ll lo=1, hi=min(N*N, (ll)1e9);
    while (lo<hi) {
        ll mid=(lo+hi)/2, cnt=0;
        
        for (ll i=1; i<=N; i++) {
            cnt+=min(N, mid/i);
        }

        if (cnt>=K) hi=mid;
        else lo=mid+1;
    }
    cout << lo;
}
