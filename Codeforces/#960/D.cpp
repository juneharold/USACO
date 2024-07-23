#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <numeric>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int t=0;

void solve() {
    int n; cin >> n;
    vector<int> a(n+5, 0);
    for (int i=1; i<=n; i++) cin >> a[i];
    /*if (t==282) {
        cout << n << "\n";
        for (int i=1; i<=n; i++) cout << a[i] << ' ';
        cout << endl;
    }
    else if (t>10) {
        return;
    }*/

    int ans=0;
    for (int i=1; i<=n; i++) {
        if (a[i]>4) {
            ans++;
            a[i]=0;
        }
        if (a[i]==3) a[i]=4;
        if (a[i]==1) a[i]=2;
    }

    for (int i=1; i<=n; i++) {
        if (a[i-1]==0 && a[i]==4) {
            ans++;
            a[i]=0;
        }
    }
    for (int i=n; i>=1; i--) {
        if (a[i+1]==0 && a[i]==4) {
            ans++;
            a[i]=0;
        }
    }

    for (int i=1; i<=n; i++) {
        if (a[i]==2) {
            int j=i+1, cnt=0;
            while (j<=n && a[j]>2) {
                cnt++;
                j++;

            }
            if (cnt%2==0 && j<=n) {
                ans+=j-i;
                for (int k=i; k<=j; k++) a[k]=0;
                i=j;
            }
            else i=j-1;
        }
    }
    for (int i=1; i<=n; i++) {
        if (a[i]!=0) ans++;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        t++;
        solve();
    }
}
