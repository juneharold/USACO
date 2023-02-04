#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#define ll long long

ll a[400005]={}, cnt[400005]={};

ll SumDigit(ll n) {
    ll ret=0;
    while (n>0) {
        ret+=n%10;
        n/=10;
    }
    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T; cin >> T;
    while (T--) {
        ll n, q; cin >> n >> q;
        set<ll> s;
        for (ll i=1; i<=n; i++) {
            cin >> a[i];
            s.insert(i);
        }

        for (ll i=0; i<q; i++) {
            ll type; cin >> type;
            if (type==1) {
                ll l, r; cin >> l >> r;
                if (s.size()==0) continue;
                auto it=s.lower_bound(l);
                vector<ll> to_erase;
                while (true) {
                    if (it==s.end()) break;
                    ll cur=(*it);
                    if (cur>r || cur<=0) break;
                    //cout << "cur: " << cur << endl;
                    a[cur]=SumDigit(a[cur]);
                    cnt[cur]++;
                    if(cnt[cur]==3) to_erase.push_back(cur);
                    it++;
                }
                for (auto er: to_erase) s.erase(er);
            }
            else {
                ll x; cin >> x;
                cout << a[x] << "\n";
            }
        }

        for (ll i=1; i<=n; i++) {
            a[i]=0; cnt[i]=0;
        }
    }
}

/*
1
5 8
1 420 69 1434 2023
1 2 3
2 2
2 3
2 4
1 2 5
2 1
2 3
2 5

*/