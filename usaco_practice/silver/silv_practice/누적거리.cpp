#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

#define f first
#define s second

const long long MAX=2e5+5;
long long N, Q, pfs=0, sfs=0;
map<long long, long long> town, ans;
vector<pair<long long, long long>> stops; //second에서 1==town, 2==meeting place.
vector<long long> idx;


int main()
{
    cin >> N >> Q;
    for (int i=0; i<N; i++) {
        long long a, x; cin >> a >> x;
        town[x]=a;
        stops.push_back({x, 1});
    }
    for (int i=0; i<Q; i++) {
        long long q; cin >> q;
        ans[q]=0;
        stops.push_back({q, 2});
        idx.push_back(q);
    }

    sort(stops.begin(), stops.end());

    //pfs first
    long long people=0;
    for (int i=0; i<stops.size(); i++) {
        long long cur=stops[i].f, type=stops[i].s;
        if (type==1) {
            if (i-1>=0) {
                pfs+=people*abs(cur-stops[i-1].f);
            }
            people+=town[cur];
        }
        if (type==2) {
            if (i-1>=0) {
                pfs+=people*abs(cur-stops[i-1].f);
            }
            ans[cur]+=pfs;
        }
    }

    // sfs
    reverse(stops.begin(), stops.end());
    people=0;
    for (int i=0; i<stops.size(); i++) {
        long long cur=stops[i].f, type=stops[i].s;
        if (type==1) {
            if (i-1>=0) {
                sfs+=people*abs(cur-stops[i-1].f);
            }
            people+=town[cur];
        }
        if (type==2) {
            if (i-1>=0) {
                sfs+=people*abs(cur-stops[i-1].f);
            }
            ans[cur]+=sfs;
        }
    }

    for (int i=0; i<idx.size(); i++) {
        cout << ans[idx[i]] << "\n";
    }
}
