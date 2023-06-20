#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n; cin >> n;
    int cnt=0, temp=5;
    while (temp<=n) {
        cnt+=n/temp;
        temp*=5;
    }
    cout << cnt;
}