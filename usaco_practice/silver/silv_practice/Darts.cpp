#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll N, M, points[1005]={};
vector<ll> sum;

int main()
{
    cin >> N >> M;
    for (ll i=1; i<=N; i++) {
        cin >> points[i];
    }

    for (ll i=0; i<=N; i++) {
        for (ll j=0; j<=N; j++) {
            sum.push_back(points[i]+points[j]);
        }
    }
    sort(sum.begin(), sum.end());

    ll ans=0;
    for (long long a : sum) {
        auto it=upper_bound(sum.begin(), sum.end(), M-a);
        if (it==sum.begin()) continue;
        it--;
        ans=max(ans, a+*it);
    }
    cout << ans;
}

/*
3 3
2
1
1
*/
