#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=9e18;

int find_type(pii x) {
    if (x.fs=='L' && x.sc=='I') return 1;
    if (x.fs=='I' && x.sc=='L') return 1;
    if (x.fs=='I' && x.sc=='T') return 2;
    if (x.fs=='T' && x.sc=='I') return 2;
    if (x.fs=='L' && x.sc=='T') return 3;
    if (x.fs=='T' && x.sc=='L') return 3;
    return -1;
}

int n;
int a=0, b=0, c=0, x=0, y=0, z=0;
void calculate(string &s) {
    a=0, b=0, c=0, x=0, y=0, z=0;
    for (int i=0; i<n; i++) {
        if (i+1<n && find_type({s[i], s[i+1]})==1) a++;
        if (i+1<n && find_type({s[i], s[i+1]})==2) b++;
        if (i+1<n && find_type({s[i], s[i+1]})==3) c++;

        if (s[i]=='L') x++;
        if (s[i]=='I') y++;
        if (s[i]=='T') z++;
    }
}

vector<int> ans;

bool operation(string &s, int type) {
    for (int i=0; i+1<n; i++) {
        if (find_type({s[i], s[i+1]})==type) {
            ans.push_back(i+1);
            break;
        }
        if (i+1==n-1) return false;
    }
    if (n==1) return false;
    if (type==1) s.insert(ans.back(), "T");
    if (type==2) s.insert(ans.back(), "L");
    if (type==3) s.insert(ans.back(), "I");

    n=s.size();
    return true;
}


void solve() {
    cin >> n;
    string s; cin >> s;

    ans.clear();

    calculate(s);
    int N=n;

    int idx=0;
    while (x!=y || y!=z || z!=x) {
        // cout << x << ' ' << y << ' ' << z << endl;
        // cout << s << endl;
        idx++;
        if (idx>2*N+10) {
            cout << "-1\n";
            return;
        }
        // 2 -> L, 3 -> I, 1-> T
        if (max({x, y, z})==x) {
            int first, second;
            if (y<z) first=3, second=1;
            else first=1, second=3;

            bool result=operation(s, first);
            if (!result) {
                result=operation(s, second);
                if (!result) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        else if (max({x, y, z})==y) {
            int first, second;
            if (x<z) first=2, second=1;
            else first=1, second=2;

            bool result=operation(s, first);
            if (!result) {
                result=operation(s, second);
                if (!result) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        else {
            int first, second;
            if (x<y) first=2, second=3;
            else first=3, second=2;

            bool result=operation(s, first);
            if (!result) {
                result=operation(s, second);
                if (!result) {
                    cout << "-1\n";
                    return;
                }
            }
        }
        calculate(s);
    }

    cout << ans.size() << "\n";
    for (int a: ans) cout << a << "\n";
    ans.clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
