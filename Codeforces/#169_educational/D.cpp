#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define fs first
#define sc second
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7, INF=1e18;

string type[nmax];

vector<int> pos[6];

void solve() {
    int n, q; cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> type[i];
    map<string, int> mp;
    mp["BG"]=0, mp["BR"]=1, mp["BY"]=2, mp["GR"]=3, mp["GY"]=4, mp["RY"]=5;
    for (int i=1; i<=n; i++) pos[mp[type[i]]].push_back(i);
    
    int x, y; 
    while (q--) {
        cin >> x >> y;
        if (x>y) swap(x, y);
        if (type[x][0]==type[y][0] || type[x][0]==type[y][1] || type[x][1]==type[y][0] || type[x][1]==type[y][1]) {
            cout << abs(x-y) << "\n";
            continue;
        }
        string mid="";
        int ans=1e9;
        for (int i=0; i<2; i++) for (int j=0; j<2; j++) {
            if (type[x][i]==type[y][j]) continue;
            mid="";
            mid+=(char)min(type[x][i], type[y][j]);
            mid+=(char)max(type[x][i], type[y][j]);
            //cout << "mid: " << mid <<' ' << min(type[x][i], type[y][j]) << ' ' << max(type[x][i], type[y][j])<<endl;
            auto it=lower_bound(pos[mp[mid]].begin(), pos[mp[mid]].end(), x);
            if (it!=pos[mp[mid]].end()) {
                ans=min(ans, abs((*it)-x)+abs((*it)-y));
            }
            if (it!=pos[mp[mid]].begin()) {
                it--;
                ans=min(ans, abs((*it)-x)+abs((*it)-y));
            }
        }
        cout << (ans==1e9 ? -1 : ans) << "\n";
    }

    for (int i=0; i<6; i++) pos[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
