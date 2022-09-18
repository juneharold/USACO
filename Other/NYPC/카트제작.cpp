#include<iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

map<string, ll> m;
map<ll, string> Name;
vector<pair<ll, ll>> parts[5];
ll synergy[605][605]={};
vector<pair<pair<ll, ll>, pair<ll, ll>>> bhw[605]; // body, handle, wheel
vector<pair<pair<ll, ll>, pair<ll, ll>>> beb; // body, engine, booster

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N; cin >> N;
    for (ll i=1; i<=N; i++) {
        string type, name; ll s;
        cin >> type >> name >> s;
        m[name]=i;
        Name[i]=name;
        if (type=="Body") parts[0].push_back({i, s});
        if (type=="Handle") parts[1].push_back({i, s});
        if (type=="Wheel") parts[2].push_back({i, s});
        if (type=="Engine") parts[3].push_back({i, s});
        if (type=="Booster") parts[4].push_back({i, s});
    }
    ll M; cin >> M;
    for (ll i=0; i<M; i++) {
        string a, b; ll w;
        cin >> a >> b >> w;
        synergy[m[a]][m[b]]=w;
        synergy[m[b]][m[a]]=w;
    }
    ll S; cin >> S;

    for (auto body: parts[0]) {
        for (auto handle: parts[1]) {
            for (auto wheel: parts[2]) {
                ll score=body.s+handle.s+wheel.s;
                score+=synergy[body.f][handle.f]+synergy[body.f][wheel.f]+synergy[handle.f][wheel.f];
                bhw[body.f].push_back({{score, body.f}, {handle.f, wheel.f}});
            }
        }
    }
    for (auto body: parts[0]) {
        for (auto engine: parts[3]) {
            for (auto booster: parts[4]) {
                ll score=engine.s+booster.s;
                score+=synergy[body.f][engine.f]+synergy[body.f][booster.f]+synergy[engine.f][booster.f];
                beb.push_back({{score, body.f}, {engine.f, booster.f}});
            }
        }
    }
    for (ll i=1; i<=N; i++) sort(bhw[i].begin(), bhw[i].end());

    ll closest=9e18;
    vector<string> ans;
    for (auto x: beb) {
        ll idx=x.f.s;
        ll lo=0, hi=bhw[idx].size()-1;
        while (lo<hi) {
            ll mid=(lo+hi)/2;
            if (bhw[idx][mid].f.f>=S-x.f.f) hi=mid;
            else lo=mid+1;
        }
        ll temp=x.f.f+bhw[idx][lo].f.f;
        if (abs(S-temp)<closest) {
            ans={Name[bhw[idx][lo].f.s], Name[bhw[idx][lo].s.f], Name[bhw[idx][lo].s.s], Name[x.s.f], Name[x.s.s]};
            closest=abs(S-temp);
        }
        if (lo>0) {
            lo--;
            temp=x.f.f+bhw[idx][lo].f.f;
            if (abs(S-temp)<closest) {
                ans={Name[bhw[idx][lo].f.s], Name[bhw[idx][lo].s.f], Name[bhw[idx][lo].s.s], Name[x.s.f], Name[x.s.s]};
                closest=abs(S-temp);
            }
        }
    }

    for (string parts: ans) cout << parts << "\n";
}
