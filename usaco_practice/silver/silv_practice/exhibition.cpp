#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

const int MAX=1e5+5;
int N, M, frame[MAX]={};
pair<int, int> pic[MAX]={};
multiset<int> s;

int main()
{
    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        cin >> pic[i].f >> pic[i].s;
    }
    for (int i=1; i<=M; i++) cin >> frame[i];

    sort(&pic[1], &pic[N+1]);
    sort(&frame[1], &frame[M+1]);

    int idx=1, ans=0, prev=0;
    for (int i=1; i<=M; i++) {
        while (idx<=N) {
            if (pic[idx].f<=frame[i]) {
                s.insert(pic[i].s);
                idx++;
            }
            else break;
        }

        while (!s.empty()) {
            if (*s.begin()<prev) s.erase(s.begin());
            else break;
        }

        for (auto x: s) cout << x << " ";
        cout << "\n";

        if (!s.empty()) {
            s.erase(s.begin());
            ans++;
        }
    }
    cout << ans;
}
