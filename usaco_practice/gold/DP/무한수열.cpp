#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

long long n, p, q;
map<long long, long long> dp;

long long recursive (long long cur) {
    if (dp.count(cur)) return dp[cur];
    else return dp[cur]=recursive(cur/p)+recursive(cur/q);
}

int main()
{
    cin >> n >> p >> q;
    dp[0]=1;
    long long ans=recursive(n);
    cout << ans;
}
