#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll mn=1, mx=9e18;
void query1() {
    ll a, b, n; cin >> a >> b >> n;
    ll hmin=0, hmax=0;
    if (n>=2) hmin=(n-2)*(a-b)+a+1, hmax=(n-1)*(a-b)+a;
    else hmin=1, hmax=a;
    if (hmax<mn || mx<hmin) {
        cout << "0 ";
        return;
    }
    mx=min(mx, hmax), mn=max(mn, hmin);
    cout << "1 ";
    return;
}

ll find_days(ll a, ll b, ll h) {
    if (a>=h) return 1;
    if ((h-a)%(a-b)==0) return (h-a)/(a-b)+1;
    else return (h-a)/(a-b)+2;
}

void query2() {
    ll a, b; cin >> a >> b;
    if (find_days(a, b, mn)==find_days(a, b, mx)) cout << find_days(a, b, mn) << ' ';
    else cout << "-1 ";
}

int main()
{
    int T; cin >> T;
    while (T--) {
        int q; cin >> q;
        while (q--) {
            int type; cin >> type;
            if (type==1) query1();
            else query2();
            //cout << mn << ' ' << mx << endl;
        }
        cout << "\n";
        mn=0, mx=1e18;
    }
}

/*
1
5
1 3 1 3
*/