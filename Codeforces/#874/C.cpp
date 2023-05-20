#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;
#define f first
#define s second

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            a.push_back(x);
        }

        // check if all elements is even
        bool all_even=true;
        for (int i=0; i<n; i++) if (a[i]%2==1) all_even=false;
        if (all_even) {
            cout << "YES\n";
            continue;
        }

        // check if smallest element is odd
        int mn=2e9;
        for (int i=0; i<n; i++) mn=min(mn, a[i]);
        if (mn%2==1) {
            cout << "YES\n";
            continue;
        }
        
        cout << "NO\n";
    }
}
