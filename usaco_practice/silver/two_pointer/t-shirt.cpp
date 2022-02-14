#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

const int MAX=1e5+5;
pair<int, int> arr[MAX]={};
int N, T[MAX]={};
set<int> s;

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> arr[i].f;
    for (int i=1; i<=N; i++) cin >> arr[i].s;
    for (int i=1; i<=N; i++) cin >> T[i];

    sort(&arr[1], &arr[N]);
    sort(&T[1], &T[N]);

    int idx=1, ans=0;
    for (int i=1; i<=N; i++) {
        while (idx<=N && arr[idx].f<=T[i]) {
            s.insert(arr[idx].s);
            idx++;
        }
        while (!s.empty() && *s.begin()<T[i]) {
            s.erase(s.begin());
        }

        if (!s.empty()) {
            s.erase(s.begin());
            ans++;
        }
    }
    cout << ans;
}
