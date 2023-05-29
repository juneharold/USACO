#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define f first
#define s second
#define ll long long
#define MOD 1000000007

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int prev=0;
        for (int i=0; i<n; i++) {
            int a; cin >> a;
            cout << n+1-a << ' '; 
        }
        cout << "\n";
    }
}
