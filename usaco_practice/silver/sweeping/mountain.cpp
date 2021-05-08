#include <iostream>
#include <algorithm>
using namespace std;

pair <int, int> xy[100005];

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> xy[i].first >> xy[i].second;
    sort(xy, xy+n);
    int ans=1;
    pair <int, int> M=make_pair(xy[0].first, xy[0].second);
    for (int i=1; i<n; i++) {
        /*
        현재 산을 전에 나온 최대 위치의 산과 비교...
        현재 산을 하나 전의 산과 비교...
        */
        int x_diff=xy[i].first-M.first, y_diff=M.second-xy[i].second;
        if (y_diff<0) {
            ans++;
            M=make_pair(xy[i].first, xy[i].second);
        }
        else if (abs(x_diff)>abs(y_diff)) {
            ans++;
            M=make_pair(xy[i].first, xy[i].second);
        }

    }
}
