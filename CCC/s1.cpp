#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define f first
#define s second
#define ll long long

int main()
{
    int n; cin >> n;
    int ans=0;
    for (int i=0; i<=250000; i++) {
        if (n-4*i>=0 && (n-4*i)%5==0) ans++;
    }
    cout << ans;
}
