#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define f first
#define s second

ll light[150005]={}, n, l;

int main()
{
    cin >> n >> l;
    for (int i=0; i<n; i++) {
        cin >> light[i];
    }

    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        v.push_back({light[i]-l, 0});
        v.push_back({light[i]+l, 1});
    }
    sort(v.begin(), v.end());

    ll ans=0, cnt=1;

    for (int i=1; i<2*n; i++) {
        if (cnt>=2) ans+=v[i].f-v[i-1].f;

        if (v[i].s==0) cnt++;
        else cnt--;
    }
    cout << ans;
}

/*
6 3
-6 -2 1 3 8 15

2 3
-1 0
*/
