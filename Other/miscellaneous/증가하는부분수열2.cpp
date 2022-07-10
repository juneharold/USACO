#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

int main()
{
    int N, ans=1; cin >> N;
    vector<int> v;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        if (v.size()==0) v.push_back(x);

        auto it=lower_bound(v.begin(), v.end(), x);
        if (it==v.end()) {
            v.push_back(x);
            ans=max(ans, (int)v.size());
        }
        else {
            ans=max(ans, (int)(it-v.begin()));
            *it=x;
        }
    }
    cout << ans;
}
