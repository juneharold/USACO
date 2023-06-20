#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        if (b<a) swap(a, b);

        if ((b-a)>a || (a-(b-a))%3) cout << "NO\n";
        else cout << "YES\n";
    }
}
