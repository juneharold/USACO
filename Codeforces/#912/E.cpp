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

void solve() {
    int n; cin >> n;
    if (n==-1) {
        exit(0);
    }
    int sx, sy; cin >> sx >> sy;

    int cnt1=0, cnt2=0;
    vector<int> point1, point2;
    for (int i=1; i<=n; i++) {
        int x, y; cin >> x >> y;
        if ((x^y)%2) point1.push_back(i), cnt1++;
        else point2.push_back(i), cnt2++;
    }

    //cout << cnt1 << ' ' << cnt2 << endl;

    vector<int> order, used(n+1, 0);
    int turn=0;
    if ((sx^sy)%2) {
        if (cnt1>=cnt2) {
            cout << "First\n"; cout.flush();
            order.insert(order.end(), point2.begin(), point2.end());
            order.insert(order.end(), point1.begin(), point1.end());
        }
        else {
            cout << "Second\n"; cout.flush();
            order.insert(order.end(), point1.begin(), point1.end());
            order.insert(order.end(), point2.begin(), point2.end());
            turn++;
        }
    }
    else {
        if (cnt2>=cnt1) {
            cout << "First\n"; cout.flush();
            order.insert(order.end(), point1.begin(), point1.end());
            order.insert(order.end(), point2.begin(), point2.end());
        }
        else {
            cout << "Second\n"; cout.flush();
            order.insert(order.end(), point2.begin(), point2.end());
            order.insert(order.end(), point1.begin(), point1.end());
            turn++;
        }
    }

    //for (int x: order) cout << x << endl;

    //cout << turn << endl;

    int idx=0, cnt_moves=n;
    while (cnt_moves--) {
        if (turn%2) {
            int i; cin >> i;
            used[i]=1;
        }
        else {
            while (idx<order.size() && used[order[idx]]) { idx++; }
            if (idx==order.size()) break;
            cout << order[idx] << "\n"; cout.flush();
            used[order[idx]]=1;
            idx++;
        }
        turn++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T=1; cin >> T;
    while (T--) {
        solve();
    }
}
