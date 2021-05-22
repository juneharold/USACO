#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> cow;

int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n, t; cin >> n >> t;
    for (int i=0; i<n; i++) {
        int d; cin >> d;
        cow.push_back(d);
    }
    int low=1, high=n;
    while (low<high) {
        int mid=(low+high)/2;
        int time=0;
        multiset <int> stage;
        for (int i=0; i<mid; i++) stage.insert(cow[i]);
        int ind=mid;
        while (stage.size()>0) {
            time+=max(0, *stage.begin()-time);
            stage.erase(stage.begin());
            if (ind!=n) {
                stage.insert(time+cow[ind]);
                ind++;
            }
        }
        //cout << mid << " " << time << "\n";
        if (time>t) low=mid+1;
        else high=mid;
    }
    cout << low;
}
