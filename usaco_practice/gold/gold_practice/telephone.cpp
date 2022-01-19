#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long

const ll MAX=5e4+5;
ll N, K, cows[MAX], visit[MAX][55]={}, ans=1e18;
char S[55][55];
priority_queue<pair<ll, pair<ll, ll>>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (ll i=1; i<=N; i++) cin >> cows[i];
    for (ll i=1; i<=K; i++) for (ll j=1; j<=K; j++) cin >> S[i][j];

    fill(&visit[0][0], &visit[MAX-1][54], 1e18);
    visit[1][cows[1]]=0;
    pq.push({0, {1, cows[1]}});

    while (!pq.empty()) {
        ll loc=pq.top().s.f, breed=pq.top().s.s, d=-pq.top().f;
        pq.pop();

        if (loc+1<=N && d+1<visit[loc+1][breed]) {
            visit[loc+1][breed]=d+1;
            pq.push({-(d+1), {loc+1, breed}});
        }
        if (loc-1>=1 && d+1<visit[loc-1][breed]) {
            visit[loc-1][breed]=d+1;
            pq.push({-(d+1), {loc-1, breed}});
        }

        if (S[breed][cows[loc]]=='1' && d<visit[loc][cows[loc]]) {
            visit[loc][cows[loc]]=d;
            pq.push({-d, {loc, cows[loc]}});
        }
    }
    
    for (int i=1; i<=K; i++) {
        if (S[i][cows[N]]=='1') ans=min(ans, visit[N][i]);
    }
    if (ans==1e18) cout << -1;
    else cout << ans;
}
