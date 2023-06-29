#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
#define f first
#define s second

ll c1=1e12, c2=1e12+1;

void solve() {
    string S; cin >> S;
    int n=S.size();
    int cnt0=0, cnt1=count(S.begin(), S.end(), '1');
    ll ans=1e18;
    for (int i=0; i<n; i++) {
        if (S[i]=='0') cnt0++;
        ll keep=cnt0+cnt1;
        ans=min(ans, (n-keep)*c2);
        if (i<n-1 && S[i]=='1' && S[i+1]=='0') {
            ans=min(ans, (n-keep-1)*c2+c1);
        }
        if (S[i]=='1') cnt1--;
    }
    cout << ans << "\n";
}

int main()
{
    int T; cin >> T;
    while (T--) {
        solve();
    }
}