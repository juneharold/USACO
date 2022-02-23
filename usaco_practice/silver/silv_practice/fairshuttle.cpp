#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

int K, N, C, ans=0;
pair<int, pair<int, int>> group[50005]={};
multiset<int> ms;

int main()
{
    cin >> K >> N >> C;
    for (int i=1; i<=K; i++) {
        cin >> group[i].f >> group[i].s.f >> group[i].s.s;
    }
    group[K+1]={N, {1e9, 0}};

    sort(&group[1], &group[K+2]);

    for (int i=1; i<=K+1; i++) {
        while (!ms.empty()) {
            if (*ms.begin()<=group[i].f) {
                ms.erase(ms.begin());
                ans++;
            }
            else break;
        }

        int cnt=group[i].s.s, des=group[i].s.f;
        while (ms.size()<C && cnt>=1) {
            ms.insert(des);
            cnt--;
        }

        while (!ms.empty() && cnt>=1) {
            if (*--ms.end()>=des) {
                ms.erase(--ms.end());
                ms.insert(des);
                cnt--;
            }
            else break;
        }

    }
    cout << ans;
}
