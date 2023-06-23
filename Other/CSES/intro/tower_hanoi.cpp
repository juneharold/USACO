#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(int n, int a, int b, int c) {
    if (n==1) {
        cout << a << ' ' << c << "\n";
        return;
    }
    solve(n-1, a, c, b);
    solve(1, a, b, c);
    solve(n-1, b, a, c);
}

int main()
{
    int n; cin >> n;
    cout << (1<<n)-1 << "\n";
    solve(n, 1, 2, 3);
}