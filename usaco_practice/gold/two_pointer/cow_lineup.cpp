#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

pair <int, int> cow[100000];
set <int> u;

int main()
{
    int n; cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cow[i].first >> cow[i].second;
        u.insert(cow[i].second);
    }
    sort(cow, cow+n);
    int active[100000];
    int left=0, right=0;
    int Min=1e9;
    while (true) {
        /*
        유니크하고
        */
        bool ind=true;
        for (int a : u) {
            if (active[a]==0) ind=false;
        }
        if (ind==true and cow[right].first-cow[left].second<Min) Min=cow[right].first-cow[left].second;

        if (ind==false and right==n) break;

        if (ind==false) {
            right++;
        }
        else if (ind==true and active[cow[left].second]>1) {
            right++;
        }
        else {
            left++;
        }
    }
    cout << Min;
}
