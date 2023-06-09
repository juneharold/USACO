#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vector<int> a(3);
    for (int i=0; i<3; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int mn=2;
    if (a[2]-a[1]-1!=0) mn=min(mn, a[2]-a[1]-1);
    if (a[1]-a[0]-1!=0) mn=min(mn, a[1]-a[0]-1);
    if (a[2]-a[1]-1==0 && a[1]-a[0]-1==0) mn=0;
    cout << mn << "\n" << max(0, max(a[2]-a[1]-1, a[1]-a[0]-1));
}
