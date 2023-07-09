#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int T; cin >> T;
    while (T--) {
        ll d, k; cin >> d >> k;
        ll n=0;
        while (2*(n*k)*(n*k)<d*d) {
            n++;
        }
        n--;
        if ((n*k+k)*(n*k+k)+(n*k)*(n*k)<=d*d) cout << "Ashish\n";
        else cout << "Utkarsh\n";
    }
}
