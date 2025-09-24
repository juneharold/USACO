#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

set<ll> s;

void solve() {
    ll A, B, M; cin >> A >> B >> M;
    ll ans=0;
    for (ll x: s) {
        if (A<=x && x<=B && x%M==0) {
            //cout << x << endl;
            ans++;
        }
    }
    cout << ans << "\n";
}

struct CompareByLength {
    bool operator()(const string& a, const string& b) const {
        /*if (a.size() == b.size()) {
            // If lengths are equal, sort lexicographically to ensure uniqueness
            return a < b;
        }*/
        return a.size() <= b.size();
    }
};

set<string, CompareByLength> monotonicNum(char cur, int cnt) {
    set<string, CompareByLength> ret;
    string temp="";
    temp+=cur;
    ret.insert(temp);
    if (cnt==10) return ret;
    for (char nx=cur; nx>='1'; nx--) {
        set<string, CompareByLength> res=monotonicNum(nx, cnt+1);
        for (string ss: res) {
            temp=cur;
            temp+=ss;
            ret.insert(temp);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("cottontail_climb_part_2_validation_input.txt", "r", stdin);
    freopen("A2out.txt", "w", stdout);
    for (char i='1'; i<='9'; i++) {
        set<string, CompareByLength> res=monotonicNum(i, 1);
        vector<string> v;
        for (string x: res) v.push_back(x);
        //cout << res.size() << endl;
        int j1=0, j2=0;
        for (int i=0; i<v.size(); i++) {
            if (i!=0 && v[i].size()!=v[i-1].size()) j1=j2;
            while (j2<v.size() && v[i].size()==v[j2].size()) {j2++;}
            for (int j=j1; j<j2; j++) {
                string xx=v[i], yy=v[j];
                reverse(xx.begin(), xx.end());
                string temp=xx;
                temp+=yy.substr(1, yy.size()-1);
                //cout << temp << endl;
                if (temp.size()<19) s.insert(stoll(temp));
            }
        }
        //cout << i << "DONE!" << endl;
    }

    //for (ll x: s) if (x<200) cout << x << endl;

    int T=1; cin >> T;
    for (int t=1; t<=T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}
