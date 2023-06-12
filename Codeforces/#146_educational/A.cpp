#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        if (n%2==0) cout << "YES\n";
        else if (n%2==1 && k%2==0) cout << "NO\n";
        else if (n%2==1 && k%2==1 && n>=k) cout << "YES\n";
        else cout << "NO\n";
    }
}
