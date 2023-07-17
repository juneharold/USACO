#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define f first
#define s second

void solve() {
    int n, p; cin >> n >> p;
    vector<int> a(n+1, 0);
    map<int, int> m;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        m[a[i]]=1;
    }
    if (m.size()==p) {
        cout << "0\n";
        //out.push_back(0);
        return;
    }

    bool case1=true;
    for (int i=a[n]-1; i>=max(0, a[n]-1-2*n); i--) {
        if (m.count(i)==0) case1=false;
    }

    if (case1) {
        int mx=0;
        for (int i=p-1; i>=max(0, p-1-n); i--) {
            if (m.count(i)==0) {
                mx=i;
                break;
            }
        }
        cout << mx-a[n] << "\n";
        //out.push_back(mx-a[n]);
    }
    else {
        int k=0;
        for (int i=n-1; i>=1; i--) {
            if (a[i]!=p-1) {
                k=i;
                break;
            }
        }
        m[a[k]+1]=1;
        m[0]=1;
        m[p-1]=1;

        int mx=0;
        for (int i=a[n]-1; i>=max(0, a[n]-1-2*n); i--) {
            if (m.count(i)==0) {
                mx=i;
                break;
            }
        }
        cout << p+mx-a[n] << "\n";
        //out.push_back(p+mx-a[n]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        solve();
    }
    //for (int x: out) cout << x << "\n";
}
/*
1
3 10
9 0 4
*/