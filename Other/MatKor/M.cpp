#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

void solve() {
    int N, TC, TM; cin >> N >> TC >> TM;
    vector<int> a(N+1), b(N+1), c(N+1);
    for (int i=1; i<=N; i++) cin >> a[i] >> b[i] >> c[i];
    int lo=0, hi=TC+TM-2;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        int money=mid, tc=TC, tm=TM;
        bool possible=true;
        for (int i=1; i<=N; i++) {
            if (a[i]*tc+b[i]*tm<=c[i]) continue;
            if (a[i]>=b[i]) {
                int diff=a[i]*tc+b[i]*tm-c[i];
                int cnt=(diff+(a[i]-1))/a[i];
                if (cnt<=money) {
                    money-=cnt;
                    tc-=cnt;
                }
                else {
                    diff-=money*a[i];
                    money=0;
                    cnt=diff/(a[i]-b[i]);
                    if (cnt*(a[i]-b[i])<diff) cnt++;
                    if (cnt>TM-tm) possible=false;
                    else {
                        tm+=cnt;
                        tc-=cnt;
                    }
                }
            }
            else {
                int diff=a[i]*tc+b[i]*tm-c[i];
                int cnt=(diff+(b[i]-1))/b[i];
                if (cnt<=money) {
                    money-=cnt;
                    tm-=cnt;
                }
                else {
                    diff-=money*b[i];
                    money=0;
                    cnt=(diff+(b[i]-a[i]-1))/(b[i]-a[i]);
                    if (cnt>TC-tc) possible=false;
                    else {
                        tc+=cnt;
                        tm-=cnt;
                    }
                }
            }

            for (int i=1; i<=N; i++) if (a[i]*tc+b[i]*tm>c[i]) possible=false;

            if (possible) hi=mid;
            else lo=mid+1;
        }
    }
    cout << lo << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
