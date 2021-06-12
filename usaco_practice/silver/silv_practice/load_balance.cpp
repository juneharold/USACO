#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair <int, int> coor[1005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second<b.second;
}

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        coor[i].first=a; coor[i].second=b;
    }
    sort(coor, coor+n);

    int ans=1e9;
    for (int i=0; i<n; i++) {
        int y=coor[i].second-1;
        int top=0, bottom=0;
        for (int j=0; j<n; j++) {
            if (coor[j].second<y) bottom++;
            if (coor[j].second>y) top++;
        }
        int first=top, second=0, third=0, fourth=bottom;
        for (int j=0; j<n; j++) {
            int same_x=coor[j].first;
            for (int k=j; k<n; k++) {
                if (coor[k].first==same_x) {
                    if (coor[k].second>y) {
                        first--; second++;
                    }
                    else {
                        fourth--; third++;
                    }
                }
                else {
                    j=k-1;
                    break;
                }
            }
            int M=max(first, max(second, max(third, fourth)));
            ans=min(ans, M);
        }
    }
    cout << ans;
}
