#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int cnt=0;
        while (n>1) {
            cnt++;
            if (n%2==0 && n!=2) n=2;
            else n--;
        }
        cout << cnt << "\n";
    }
}