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
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i=0; i<n; i++) cin >> a[i];
        
        int cnt=0, sum=0;
        for (int i=0; i<n; i++) {
            sum+=a[i];
            if (i>=1 && a[i]==-1 && a[i-1]==-1) cnt=2;
            if (a[i]==-1) cnt=max(cnt, 1);
        }

        if (cnt==2) cout << sum+4 << "\n";
        if (cnt==1) cout << sum << "\n";
        if (cnt==0) cout << sum-4 << "\n";
    }
}
