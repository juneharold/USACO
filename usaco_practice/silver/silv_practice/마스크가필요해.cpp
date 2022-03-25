#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define f first
#define s second

pair<ll, ll> ppl[500005]={}, mask[500005]={};
priority_queue<ll> pq;

int main()
{
    int N, M; cin >> N >> M;
    for (int i=0; i<N; i++) cin >> ppl[i].f >> ppl[i].s;
    for (int i=0; i<M; i++) cin >> mask[i].f >> mask[i].s;

    sort(ppl, ppl+N);
    sort(mask, mask+M);

    int idx=0, ans=0;
    for (int i=0; i<M; i++) {
        while (ppl[idx].f<=mask[i].f) {
            pq.push(-ppl[idx].s);
            idx++;
        }

        int x=mask[i].s;
        while (x>0 && !pq.empty()) {
            ll tp=-pq.top();
            pq.pop();
            if (tp>=mask[i].f) {
                x--;
                ans++;
            }
        }
    }
    cout << ans;
}
