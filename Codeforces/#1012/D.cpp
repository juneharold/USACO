#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

vector<int> isprime, primes, minfactor;
void linear_sieve(int sz) {
    for (int i=0; i<=sz; i++) {
        isprime.push_back((i>1 ? 1:0));
        minfactor.push_back(i);
    }
    for (int i=2; i<=sz; i++) {
        if (isprime[i]) primes.push_back(i);
        for (int j: primes) {
            if (i*j>sz) break;
            isprime[i*j]=0;
            minfactor[i*j]=j;
            if (i%j==0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    int temp=(n+2/2)/2, target1=-1e9, target2=-1e9;
    for (int p: primes) {
        if (p>=temp) {
            target2=p;
            break;
        }
        target1=p;
    }
    int target;
    if (abs(temp-target1)<abs(temp-target2)) target=target1;
    else target=target2;

    vector<int> ans;
    ans.push_back(target);
    int idx=1;
    for (int i=1; i<n; i++) {
        if (target-idx>0) ans.push_back(target-idx);
        if (target+idx<=n) ans.push_back(target+idx);
        idx++;
    }

    for (int a: ans) cout << a << ' ';
    cout << "\n";

    // int sum=0, cnt=0;
    // for (int i=1; i<=n; i++) {
    //     sum+=ans[i-1];
    //     if (isprime[(sum+i-1)/i]) cnt++;
    // } 
    // if (cnt>=n/3-1) cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve(1e5);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
