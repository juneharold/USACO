#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    pair <int, int> xy[100005];
    for (int i=0; i<n; i++) {
        cin >> xy[i].second>> xy[i].first;
    }
    sort(xy, xy+n);
    for (int i=0; i<n; i++) {
        cout << xy[i].second << " " << xy[i].first << "\n";
    }
    return 0;
}
