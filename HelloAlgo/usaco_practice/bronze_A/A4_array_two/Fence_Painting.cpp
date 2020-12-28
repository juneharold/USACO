// Fence Painting
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int total = (b-a) + (d-c);
    int intersect = max(min(b, d)-max(a, c), 0);
    cout << total - intersect;
}
