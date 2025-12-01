#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

void flip(vector<pii> &ret, string &s, int l, int r) {
    for (int i=l; i<=r; i++) {
        if (s[i]=='0') s[i]='1';
        else s[i]='0';
    }
    ret.push_back({l+1, r+1});
}

int n;

bool check_alternating(string &s) {
    for (int i=0; i<n-1; i++) {
        if (s[i]==s[i+1]) return false;
    }
    return true;
}

vector<pii> make0(string s) {
    vector<pii> ret;
    if (check_alternating(s)) flip(ret, s, 0, 2);
    for (int i=0; i<n; i++) {
        if (s[i]!='1') continue;
        int to=i;
        for (int j=i+1; j<n; j++) {
            if (s[j]=='0') break;
            to=j;
        }
        if (to!=i) {
            flip(ret, s, i, to);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (s[j]=='1') {
                if (j-2>=0 && s[j-1]=='0' && s[j-2]=='0') {
                    flip(ret, s, j-2, j-1);
                    flip(ret, s, j-2, j);
                    break;
                }
                else if (j+2<n && s[j+1]=='0' && s[j+2]=='0') {
                    flip(ret, s, j+1, j+2);
                    flip(ret, s, j, j+2);
                    break;
                }
            }
        }
    }
    return ret;
}

void solve() {
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<pii> res1=make0(s);
    vector<pii> res2=make0(t);
    reverse(res2.begin(), res2.end());

    cout << res1.size()+res2.size() << "\n";
    for (auto p: res1) cout << p.fs << ' ' << p.sc << "\n";
    for (auto p: res2) cout << p.fs << ' ' << p.sc << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
