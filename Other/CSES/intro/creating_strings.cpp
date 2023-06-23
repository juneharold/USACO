#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

set<string> ans;
string s; 

void solve(int cur, int n, string m) {
    if (cur==(1<<n)-1) {
        ans.insert(m);
        return;
    }
    for (int i=0; i<n; i++) {
        if ((cur&(1<<i))==0) {
            int nx=cur|(1<<i);
            string nm=m+s[i];
            solve(nx, n, nm);
        }
    }
}

int main()
{
    cin >> s;
    int n=s.size();
    solve(0, n, "");
    cout << ans.size() << "\n";
    for (string x: ans) cout << x << "\n";
}