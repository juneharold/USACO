#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int n; cin >> n;
    vector<int> p(n+1, 0);
    if (n%2==0) {
        p[n]=n;
        int pos=-1;
        for (int i=20; i>=0; i--) {
            if (n&(1<<i)) {
                pos=i;
                break;
            }
        }
        p[n-1]=(1<<pos)-1;
        p[n-2]=p[n-1]-1;
        p[n-3]=1;
        p[n-4]=3;
        set<int> s;
        for (int i=1; i<=n; i++) s.insert(i);
        s.erase(p[n]);
        s.erase(p[n-1]);
        s.erase(p[n-2]);
        s.erase(p[n-3]);
        s.erase(p[n-4]);
        int i=0;
        for (int x: s) p[++i]=x;
    }
    else {
        p[n]=n;
        p[n-1]=n-1;
        p[n-2]=1;
        p[n-3]=3;
        set<int> s;
        for (int i=1; i<=n; i++) s.insert(i);
        s.erase(p[n]);
        s.erase(p[n-1]);
        s.erase(p[n-2]);
        s.erase(p[n-3]);
        int i=0;
        for (int x: s) p[++i]=x;
    }

    int k=0;
    for (int i=1; i<=n; i++) {
        if (i%2) k=k&p[i];
        else k=k|p[i];
    }
    cout << k << "\n";
    for (int i=1; i<=n; i++) cout << p[i] << ' ';
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
