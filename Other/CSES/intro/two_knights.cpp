#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
 
int main()
{
    int n; cin >> n;
    for (ll k=1; k<=n; k++) {
        cout << (k*k)*(k*k-1)/2-4*(k-1)*(k-2) << "\n";
    }
}