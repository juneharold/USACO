#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> v; 
        for (int i=0; i<n*k; i++) {
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int idx=v.size()-1-(n-(n+1)/2);
        long long sum=0;
        for (int i=0; i<k; i++) {
            sum+=v[idx];
            idx-=(n-(n+1)/2)+1;
        }
        cout << sum << "\n";
    }
}

