#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll N, K, M;

int main()
{
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    cin >> N >> K >> M;

    ll lo=1, hi=1e12;
    while (lo<hi) {
        ll X=(lo+hi)/2+1, n=N, k=K;

        while (k>0 && n>0) {
            ll block_sz=n/X, until=(n/X)*X;
            if (block_sz<=M) {
                n-=M*k;
                k=0;
                break;
            }
            ll days=(n-until)/block_sz+1;
            k-=days;
            n-=(days*block_sz);
        }

        if (n<=0) lo=X;
        else hi=X-1;
    }
    cout << lo;
}
