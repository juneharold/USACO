#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> a(1000, 0), isprime(2000001, 1), p, minfactor(2000001, 0);

void linear_sieve() {
    for (int i=2; i<=2000000; i++) minfactor[i]=i;
    for (int i=2; i<=2000000; i++) {
        if (isprime[i]) p.push_back(i);
        for (int j: p) {
            if (i*j>2000000) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    linear_sieve();
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (abs(a[i]-a[j])<2) continue;
            int k=minfactor[abs(a[i]-a[j])];
            int l=a[i]%k;
            v.push_back({k, l});
        }
    }

    int ans=1;
    for (auto x: v) {
        int cnt=0, k=x.first, l=x.second;
        for (int i=0; i<n; i++) {
            if ((a[i]-l+k)%k==0) cnt++;
        }
        ans=max(ans, cnt);
    }
    cout << ans;
}