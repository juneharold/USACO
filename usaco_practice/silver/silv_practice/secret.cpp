#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define ll long long

string s;
ll solve(ll len, ll idx) {
    if (len==s.size()) return idx;
    if (idx<=len/2) return solve(len/2, idx);
    else {
        ll nx=idx-1;
        if (nx<=len/2) nx=len;
        return solve(len/2, nx-len/2);
    }
}

int main()
{
    cin >> s;
    ll N, len=s.size(); cin >> N;
    while (len<N) len*=2;
    cout << s[(solve(len, N)-1+s.size())%s.size()];
}
