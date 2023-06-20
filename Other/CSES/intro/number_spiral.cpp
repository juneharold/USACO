#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int T; cin >> T;
    while (T--) {
        ll r, c; cin >> r >> c;
        if (r>=c) {
            if (r%2==0) cout << r*r-c+1 << "\n"; 
            else cout << (r-1)*(r-1)+1+c-1 << "\n";
        }
        else {
            if (c%2==1) cout << c*c-r+1 << "\n";
            else cout << (c-1)*(c-1)+1+r-1 << "\n";
        }
    }
}