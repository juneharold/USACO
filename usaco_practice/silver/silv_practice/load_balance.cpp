#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair <int, int> coorx[1005];
pair <int, int> coory[1005];

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second<b.second;
}

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        int a, b; cin >> a >> b;
        coorx[i].first=a; coorx[i].second=b;
        coory[i].first=a; coory[i].second=b;
    }
    sort(coorx, coorx+n);
    sort(coory, coory+n, cmp);

    int ans=1e9;
    for (int i=0; i<n; i++) {
        int y=coory[i].second-1;
        int top=0, bottom=0;
        for (int j=0; j<n; j++) {
            if (coory[i].second<y) bottom++;
            if (coory[i].second>y) top++;
        }
        int first=top, second=0, third=0, fourth=bottom;
        for (int j=0; j<n; j++) {
            int same_x=coorx[j].first;
            for (int k=j; k<n; k++) {
                if (coorx[k].first==same_x) {
                    if (coorx[k].second>y) {
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
