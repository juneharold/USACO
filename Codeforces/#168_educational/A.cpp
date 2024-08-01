#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int calc_time(string s) {
    int ret=2;
    for (int i=1; i<s.size(); i++) {
        if (s[i]==s[i-1]) ret++;
        else ret+=2;
    }
    return ret;
}

void solve() {
    string s; cin >> s;
    string ans;
    int mx=0;
    for (int i=0; i<=s.size(); i++) {
        for (int j=0; j<26; j++) {
            string temp=s.substr(0, i)+(char)(j+'a')+s.substr(i, s.size()-i);
            int res=calc_time(temp);
            if (res>mx) {
                ans=temp;
                mx=res;
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
