#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long
#define f first
#define s second

ll N, M, K, A, B, C, T, S[3005], ans=0;
priority_queue<ll> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> A >> B >> C >> T;
    for (int i=1; i<=M; i++) cin >> S[i];

    for (int i=1; i<=M-1; i++) {
        ll t=(S[i]-1)*B;
        if (t>T) break;
        ll reach=(T-t)/A;
        if (S[i]+reach+1>=S[i+1]) {
            ans+=S[i+1]-S[i]; //S[i] 포함.
            continue;
        }
        ans+=reach+1; //S[i] 포함.


        ll semi_pos=S[i]+reach+1, time=(S[i]-1)*B+(reach+1)*C;
        for (int j=1; j<=K-M; j++) {
            if (time>T || semi_pos>=S[i+1]) break;
            ll nreach=(T-time)/A; //nreach+1 만큼 가능.

            ll candidate=min(S[i+1]-semi_pos, nreach+1);
            if (pq.size()<K-M) pq.push(-candidate);
            else {
                ll temp=-pq.top();
                if (candidate>temp) {
                    pq.pop();
                    pq.push(-candidate);
                }
            }

            semi_pos+=nreach+1;
            time+=(nreach+1)*C;
        }
    }

    if ((S[M]-1)*B<=T) ans++;

    while (!pq.empty()) {
        ans+=-pq.top();
        pq.pop();
    }

    cout << ans-1;
}
