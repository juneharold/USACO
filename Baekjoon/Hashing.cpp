#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define f first
#define s second
typedef long long ll;
const int nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    int L; cin >> L;
    ll ans=0;
    for (int i=0; i<L; i++) {
        char c; cin >> c;
        ll x=c-'a'+1;
        for (int j=1; j<=i; j++) {
            x*=31;
            x%=1234567891;
        }
        ans+=x;
        ans%=1234567891;
    }
    cout << ans;
}