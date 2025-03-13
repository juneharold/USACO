#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int n, x;
bool possible=false;

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

void trial(vector<int> a) {
    int m=a.size(), k;
    if (m==1) {
        if (a[0]==x) possible=true;
        return;
    }
    for (int p: primes) {
        if (m%p==0) {
            k=p;
            break;
        }
    }
    vector<int> na;
    for (int i=0; i<m; i+=k) {
        int sum=0;
        for (int j=i; j<i+k; j++) {
            sum+=a[j];
        } 
        na.push_back(sum/k);
    }
    trial(na);
}

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    ll sum=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum+=a[i];
    }
    //trial(a);
    if (sum%n==0 && sum/n==x) cout << "YES\n";
    else cout << "NO\n";
    //possible=false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    linear_sieve(100);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
