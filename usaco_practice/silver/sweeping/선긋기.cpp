#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> xy[1000005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> xy[i].first >> xy[i].second;
    sort(xy, xy+n);
    int ans=xy[0].second-xy[0].first, end=xy[0].second;
    for (int i=1; i<n; i++) {
        if (xy[i].first>=end) {
            ans+=xy[i].second-xy[i].first;
            end=xy[i].second;
        }
        else if (xy[i].second>=end) {
            ans+=xy[i].second-end;
            end=xy[i].second;
        }
    }
    cout << ans;
    return 0;
}
