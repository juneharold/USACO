#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long

int X, Y, G;
pair<string, string> same[100005]={}, diff[100005]={};
map<string, int> m;

int main()
{
    cin >> X;
    for (int i=0; i<X; i++) cin >> same[i].f >> same[i].s;
    cin >> Y;
    for (int i=0; i<Y; i++) cin >> diff[i].f >> diff[i].s;
    cin >> G;
    for (int i=1; i<=G; i++) {
        string a, b, c; cin >> a >> b >> c;
        m[a]=i;
        m[b]=i;
        m[c]=i;
    }

    int ans=0;
    for (int i=0; i<X; i++) {
        if (m[same[i].f]!=m[same[i].s]) ans++;
    }
    for (int i=0; i<Y; i++) {
        if (m[diff[i].f]==m[diff[i].s]) ans++;
    }

    cout << ans;
}
