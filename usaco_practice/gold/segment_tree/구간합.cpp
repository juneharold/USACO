#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

const ll MAX = 1e6+5;
ll st[MAX*4], N, M, K;

ll query(ll nn, ll a, ll b, ll qa, ll qb)
{
	if (qb<a || qa>b) return 0;
	if (qa<=a && b<=qb) return st[nn];

	ll mid = (a+b)/2;
	return query(2*nn, a, mid, qa, qb) + query(2*nn+1, mid+1, b, qa, qb);
}

void update(ll nn, ll a, ll b, ll qa, ll qb, ll v)
{
	if (qa<=a && b<=qb) { st[nn]=v; return; }
    if (qb<a || qa>b) return;

	ll mid = (a+b)/2;
	update(2*nn, a, mid, qa, qb, v);
	update(2*nn+1, mid+1, b, qa, qb, v);
	st[nn] = st[2*nn] + st[2*nn+1];
}


int main(){
    cin >> N >> M >> K;

    for (int i=0; i<N; i++)
    {
        int t; cin >> t;
        update(1, 0, N-1, i, i, t);
    }

    for(ll i=0; i<M+K; i++){
        ll a, b, c, d;
        cin >> a >> b >> c;
        if (a == 1) {
            b--;
            update(1, 0, N-1, b, b, c);
        }
        else {
            b--; c--;
			cout << query(1, 0, N-1, b, c) << "\n";
        }
    }
}
