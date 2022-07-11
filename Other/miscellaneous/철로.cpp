/*
시작점을 pq에 넣고,
끝점 어떤 끝점이 나왔을때, 몇개의 선분이 가려지는지 구하기.
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long

priority_queue<int> pq;
pair<int, int> event[100005]={}; // 위치, 시작인지 끝인지, 번호.

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.s==b.s) return a.f<b.f;
    return a.s<b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, d; cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> event[i].f >> event[i].s;
        if (event[i].f>event[i].s) swap(event[i].f, event[i].s);
    }
    cin >> d;

    sort(&event[1], &event[n+1], cmp);

    int ans=0, sum=0;
    for (int i=1; i<=n; i++) {
        pq.push(-event[i].f);
        while (!pq.empty()) {
            int loc=-pq.top();
            if (event[i].s-loc>d) {
                sum--;
                pq.pop();
            }
            else break;
        }
        ans=max(ans, (int)pq.size());
    }
    cout << ans;
}

/*
2
1 3
3 1
2
*/
