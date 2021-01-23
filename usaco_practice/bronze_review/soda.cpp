#include <iostream>
using namespace std;

int main()
{
    int e, f, c;
    cin >> e >> f >> c;
    int drank=0;
    int total=e+f;
    while (total>=c)
    {
        int exchange=0;
        exchange=total/c;
        drank += exchange;
        total=total%c+exchange;
    }
    cout << drank;
}
