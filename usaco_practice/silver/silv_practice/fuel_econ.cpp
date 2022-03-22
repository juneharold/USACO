#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=5e4+5;
ll N, G, B, D;
pair<ll, ll> fuel[MAX]={};

int main()
{
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> G >> B >> D;
    for (ll i=1; i<=N; i++) cin >> fuel[i].f >> fuel[i].s;
    fuel[0]={0, 1e9}; fuel[N+1]={D, 0};
    sort(&fuel[0], &fuel[N+2]);

    //is it possible?
    for (ll i=1; i<=N+1; i++) {
        if (fuel[i].f-fuel[i-1].f>G) {
            cout << -1;
            exit(0);
        }
    }

    ll cur_loc=0, cur_price=1e9, cur_fuel=B, ans=0, l=1, r=1;

    for (int i=1; i<=N+1; i++) {
        if (fuel[i].f<=B && fuel[i].s<cur_price) {
            cur_fuel-=(fuel[i].f-cur_loc);
            cur_loc=fuel[i].f;
            cur_price=fuel[i].s;
            l=i+1;
            r=i+1;
        }
        else if (fuel[i].f>B) break;
    }

    while (cur_loc<D) {
        while (r<=N+1 && fuel[r].f<=cur_loc+G) r++;
        bool lower_price=false;
        int next_loc, min_price=1e9, left=l, right=r;
        for (int i=left; i<right; i++) {
            if (fuel[i].s<=cur_price) {
                min_price=fuel[i].s;
                next_loc=fuel[i].f;
                lower_price=true;
                l=i+1;
                break;
            }
            else if (fuel[i].s<min_price){
                min_price=fuel[i].s;
                next_loc=fuel[i].f;
                l=i+1;
            }
        }

        if (lower_price) {
            ll need=(next_loc-cur_loc)-cur_fuel;
            cur_fuel+=need;
            ans+=need*cur_price;
        }
        else {
            ll need=G-cur_fuel;
            cur_fuel+=need;
            ans+=need*cur_price;
        }
        cur_fuel-=(next_loc-cur_loc);
        cur_loc=next_loc;
        cur_price=min_price;
    }

    cout << ans;
}
