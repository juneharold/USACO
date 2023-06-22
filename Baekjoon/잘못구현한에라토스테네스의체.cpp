#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n; cin >> n;
    long long ans=0, j=0;
    for (int i=2; i<n; i=j+1) {
        j=(n-1)/((n-1)/i);
        ans+=((n-1)/i+1)*(j-i+1);
    }
    if (n==1) ans--;
    cout << ans+n+1;
}
