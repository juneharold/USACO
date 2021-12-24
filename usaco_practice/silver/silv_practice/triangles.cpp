#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=1e5+5, mod=1e9+7;
ll N, ans=0;
pair<ll, ll> pos[MAX], X[20005]={}, Y[20005]={}; // X 배열 인덱스에는 y좌표, Y 배열 인덱스에는 x좌표, (first에는 거리합, second에는 점 갯수)

void reset() {
    for (ll i=0; i<20005; i++) {
        X[i].f=0; X[i].s=0; Y[i].f=0; Y[i].s=0;
    }
}

bool cmp (pair<ll, ll> a, pair<ll, ll> b) {
    if (a.f==b.f) return a.s>b.s;
    return a.f<b.f;
}

int main()
{
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    cin >> N;
    for (ll i=0; i<N; i++) {
        cin >> pos[i].f >> pos[i].s;
        pos[i].f+=1e4; pos[i].s+=1e4;
    }

    sort(pos, pos+N);

    for (ll i=0; i<N; i++) {
        ll x1=pos[i].f, y1=pos[i].s;
        ll sum_base=x1*X[y1].s-X[y1].f, sum_height=y1*Y[x1].s-Y[x1].f;
        ll area=sum_base*sum_height;
        ans+=area; ans%=mod;

        //cout << sum_base << " " << sum_height << endl;

        X[y1].f+=x1; X[y1].s++;
        Y[x1].f+=y1; Y[x1].s++;
    }
    reset();

    for (ll i=N-1; i>=0; i--) {
        ll x1=pos[i].f, y1=pos[i].s;
        ll sum_base=X[y1].f-x1*X[y1].s, sum_height=Y[x1].f-y1*Y[x1].s;
        ll area=sum_base*sum_height;
        ans+=area; ans%=mod;

        //cout << sum_base << " " << sum_height << endl;

        X[y1].f+=x1; X[y1].s++;
        Y[x1].f+=y1; Y[x1].s++;
    }
    reset();

    sort(pos, pos+N, cmp);
    for (ll i=0; i<N; i++) {
        ll x1=pos[i].f, y1=pos[i].s;
        ll sum_base=x1*X[y1].s-X[y1].f, sum_height=Y[x1].f-y1*Y[x1].s;
        ll area=sum_base*sum_height;
        ans+=area; ans%=mod;

        //cout << sum_base << " " << sum_height << endl;

        X[y1].f+=x1; X[y1].s++;
        Y[x1].f+=y1; Y[x1].s++;
    }
    reset();

    for (ll i=N-1; i>=0; i--) {
        ll x1=pos[i].f, y1=pos[i].s;
        ll sum_base=X[y1].f-x1*X[y1].s, sum_height=y1*Y[x1].s-Y[x1].f;
        ll area=sum_base*sum_height;
        ans+=area; ans%=mod;

        //cout << sum_base << " " << sum_height << endl;

        X[y1].f+=x1; X[y1].s++;
        Y[x1].f+=y1; Y[x1].s++;
    }

    cout << ans%mod;
}
