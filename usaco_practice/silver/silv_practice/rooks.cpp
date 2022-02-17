#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second

int N, r[3005]={}, c[3005]={};
pair<int, pair<int, int>> row[3005]={}, col[3005]={};
priority_queue<pair<int, int>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        row[i]={a, {c, i}};
        col[i]={b, {d, i}};
    }

    sort(&row[1], &row[N+1]);
    int idx=1;
    for (int i=1; i<=N; i++) {
        while (idx<=N) {
            if (row[idx].f<=i) {
                pq.push({-row[idx].s.f, row[idx].s.s});
                idx++;
            }
            else break;
        }

        while (-pq.top().f<i) pq.pop();

        if (pq.empty()) {
            cout << "NIE";
            return 0;
        }
        else {
            r[pq.top().s]=i;
            pq.pop();
        }
    }

    sort(&col[1], &col[N+1]);
    idx=1;
    for (int i=1; i<=N; i++) {
        while (idx<=N) {
            if (col[idx].f<=i) {
                pq.push({-col[idx].s.f, col[idx].s.s});
                idx++;
            }
            else break;
        }

        while (-pq.top().f<i) pq.pop();

        if (pq.empty()) {
            cout << "NIE";
            return 0;
        }
        else {
            c[pq.top().s]=i;
            pq.pop();
        }
    }

    for (int i=1; i<=N; i++) {
        cout << r[i] << " " << c[i] << "\n";
    }
}
