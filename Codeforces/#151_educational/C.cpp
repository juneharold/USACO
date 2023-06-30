#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <random>
#include <chrono>
#include <numeric>
using namespace std;
#define f first
#define s second
typedef long long ll;
const ll nmax=2e5+5, sqrmax=635, MOD=1e9+7;

ll fastpow (ll x, ll y) {
    ll exponent=y, ret=1;
    while (exponent) {
        if (exponent%2) {
            ret*=x;
            ret%=MOD;
        }
        x*=x;
        x%=MOD;
        exponent/=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        vector<vector<int>> pos(11);
        int n=S.size();
        for (int i=0; i<n; i++) {
            pos[S[i]-'0'].push_back(i);
        }
        int m; cin >> m;
        string l, r; cin >> l >> r;
        bool possible=false;
        int cur=-1;
        for (int i=0; i<m; i++) {
            int start=l[i]-'0', end=r[i]-'0';
            int mx=-1;
            for (int j=start; j<=end; j++) {
                int lo=0, hi=pos[j].size()-1;
                while (lo<hi) {
                    int mid=(lo+hi)/2;
                    if (cur<pos[j][mid]) hi=mid;
                    else lo=mid+1;
                }
                if (pos[j].size()==0) {
                    possible=true;
                    break;
                }
                if (lo==pos[j].size()-1 && pos[j][lo]<=cur) {
                    possible=true;
                    break;
                }
                mx=max(mx, pos[j][lo]);
            }
            cur=mx;
            //cout << cur << endl;
            if (possible) break;
        }
        if (possible) cout << "YES\n";
        else cout << "NO\n";

        for (int i=0; i<10; i++) pos[i].clear();
    }
}
/*
1
11111
3
101
291
*/