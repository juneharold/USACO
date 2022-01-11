#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll cnt_3 (ll x){return x/3;}
ll cnt_5 (ll x){return x/5;}
ll cnt_15 (ll x){return x/15;}

int main()
{
    ll N, lo=1, hi=1e18; cin >> N;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        ll cnt_num=mid-cnt_3(mid)-cnt_5(mid)+cnt_15(mid);

        if (cnt_num<N) {
            lo=mid+1;
        }
        else {
            hi=mid;
        }
    }
    cout << lo;
}
