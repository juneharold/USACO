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
const ll nmax=2e3+5, sqrmax=635, MOD=1e9+7, INF=1e18;

int n, x, pos1=1, posn=1; 

void change_x(int target) {
    while (x!=target) {
        if (x<target) {
            cout << "? " << posn << "\n"; cout.flush();
            char res; cin >> res;
            x++;
        }
        else {
            cout << "? " << pos1 << "\n"; cout.flush();
            char res; cin >> res;
            x--;
        }
    }
}

int a[nmax]={};

void find_array(int mn, int mx, vector<int> &idx) {
    if (mn>mx) return;
    int xx=(mx+mn)/2;
    change_x(xx);
    vector<int> smaller, larger;
    for (int i: idx) {
        cout << "? " << i << "\n"; cout.flush();
        char res; cin >> res;
        if (res=='>') {
            larger.push_back(i);
            x++;
        }
        else if (res=='<') {
            smaller.push_back(i);
            x--;
        }
        else a[i]=xx;
        change_x(xx);
    }
    find_array(mn, xx-1, smaller);
    find_array(xx+1, mx, larger);
}

void solve() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cout << "? " << i << "\n"; cout.flush();
        char res; cin >> res;
        if (res=='=' && posn==-1) posn=i;
        else if (res=='<' && posn!=-1) {
            cout << "? " << posn << "\n"; cout.flush();
            cin >> res;
        }
        else {
            while (res=='>') {
                posn=i;
                cout << "? " << i << "\n"; cout.flush();
                cin >> res;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << "? " << i << "\n"; cout.flush();
        char res; cin >> res;
        if (res=='=' && pos1==-1) pos1=i;
        else if (res=='>' && pos1!=-1) {
            cout << "? " << pos1 << "\n"; cout.flush();
            cin >> res;
        }
        else {
            while (res=='<') {
                pos1=i;
                cout << "? " << i << "\n"; cout.flush();
                cin >> res;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        cout << "? " << pos1 << "\n"; cout.flush();
        char res; cin >> res;
    }
    x=1;

    vector<int> v;
    for (int i=1; i<=n; i++) v.push_back(i);
    find_array(1, n, v);
    cout << "! ";
    for (int i=1; i<=n; i++) cout << a[i] << ' ';
    cout << "\n"; cout.flush();
    pos1=-1, posn=-1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}