#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

int N, D, ans=0;
pair<int, int> cow[50005];

int main()
{
    freopen("crowded.in", "r", stdin);
    freopen("crowded.out", "w", stdout);
    cin >> N >> D;
    for (int i=0; i<N; i++) cin >> cow[i].f >> cow[i].s;

    sort(&cow[0], &cow[N]);
    set<int> left, right;
    int p=0, q=0;

    for (int i=0; i<N; i++) {
        while (q<N && cow[q].f<=cow[i].f+D) {
            right.insert(cow[q].s);
            q++;
        }
        while (cow[p].f<cow[i].f-D) {
            left.erase(left.find(cow[p].s));
            p++;
        }

        if (!left.empty() && !right.empty()) {
            if (*--left.end()>=2*cow[i].s && *--right.end()>=2*cow[i].s) ans++;

        }

        left.insert(cow[i].s);
        right.erase(right.find(cow[i].s));
    }
    cout << ans;
}
