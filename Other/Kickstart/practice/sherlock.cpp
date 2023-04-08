#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    for (int t=1; t<=T; t++) {
        long long L, R; cin >> L >> R;
        long long n=min(L, R);
        cout << "Case #" << t << ": " << n*(n+1)/2 << "\n";
    }
}
