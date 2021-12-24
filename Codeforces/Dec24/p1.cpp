#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long t; cin >> t;
    for (long long c=0; c<t; c++) {
        long long n, sum=0; cin >> n;
        for (long long i=1; i<=n; i++) {
            long long a; cin >> a;
            sum+=a;
        }
        if (sum%n==0) cout << "0" << "\n";
        else cout << "1" << "\n";
    }
}
