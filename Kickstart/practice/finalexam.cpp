#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long
#define f first
#define s second

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        int N, M; cin >> N >> M;
        map<ll, ll> m;
        for (int i=1; i<=N; i++) {
            ll a, b; cin >> a >> b;
            m[a]=b;
        }
        m[-9e18]=-8e18;
        m[8e18]=9e18;

        cout << "Case #" << t << ": ";
        for (int i=1; i<=M; i++) {
            ll x; cin >> x;
            auto it1=m.lower_bound(x);
            pair<ll, ll> p1=*it1;
            auto it2=it1;
            it2--;
            pair<ll, ll> p2=*it2;

            if (x==p1.f) {
                cout << p1.f << " ";
                m.erase(it1);
                if (x+1<=p1.s) m[x+1]=p1.s;
            }
            else if (p2.f<=x && x<=p2.s){
                cout << x << " ";
                m.erase(it2);
                if (x+1<=p2.s) m[x+1]=p2.s;
                if (p2.f<=x-1) m[p2.f]=x-1;
            }
            else {
                if (x-p2.s<=p1.f-x) {
                    cout << p2.s << " ";
                    m.erase(it2);
                    if (p2.f!=p2.s) m[p2.f]=p2.s-1;
                }
                else {
                    cout << p1.f << " ";
                    m.erase(it1);
                    if (p1.f!=p1.s) m[p1.f+1]=p1.s;
                }
            }
        }
        cout << "\n";
    }
}
