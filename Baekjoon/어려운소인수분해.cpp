#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> factor(5000005);

void solve(ll k) { // k를 소인수분해 
    while (k!=1) {
        cout << factor[k] << ' ';
        k/=factor[k];
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (ll i=2; i<=5000000; i++) factor[i]=i;
    for (ll i=2; i*i<=5000000; i++) {
        for (ll j=i*i; j<=5000000; j+=i) {
            factor[j]=min(factor[j], i);
        }
    }
    ll n; cin >> n;
    for (ll i=0; i<n; i++) {
        ll k; cin >> k;
        solve(k);
    }
}