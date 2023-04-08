#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll used[200005]={};

int main() 
{
    ll T; cin >> T;
    while (T--) {
        ll n, k, x; cin >> n >> k >> x;
        ll Max_bit=0;
        for (ll i=0; i<=30; i++) {
            if (x&(1<<i)) Max_bit=i;
        }
        ll cnt=0; // maximum number of subsequence
        for (ll i=1; i<=n; i++) {
            if (i&(1<<Max_bit)) cnt++;
        }

        if (k>cnt || (cnt-k)%2==1) {
            cout << "NO\n";
            continue;
        }

        vector<vector<ll>> ans;
        //cout << "YES\n";
        for (ll i=1; i<=n; i++) {
            if (k==1) break;
            if (i==x && used[i]==0) {
                ans.push_back({1, x});
                //cout << "1 " << x << "\n";
                used[i]=1;
                k--;
            }
            else if (used[i]==0 && used[(i^x)]==0) {
                ans.push_back({2, i, (i^x)});
                //cout << "2 " << i << ' ' << (i^x) << "\n";
                used[i]=1, used[(i^x)]=1;
                k--;
            }
        }

        ll res=2e9;
        for (ll i=1; i<=n; i++) {
            if (used[i]==0 && res==2e9) res=i;
            else if (used[i]==0) res=(res^i);
        }
        if (res!=x) {
            cout << "NO\n";
            continue;
        }

        ll left=0;
        for (ll i=1; i<=n; i++) {
            if (used[i]==0) left++;
        }
        vector<ll> v; v.push_back(left);
        for (ll i=1; i<=n; i++) {
            if (used[i]==0) v.push_back(i); //cout << i << ' ';
        }
        ans.push_back(v);
        //cout << "\n";

        cout << "YES\n";
        for (auto v: ans) {
            for (ll i: v) {
                cout << i << ' ';
            }
            cout << "\n";
        }

        fill(&used[0], &used[n+1], 0);
    }
}
/*
1
10 4 3

*/