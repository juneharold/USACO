#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, f, b, acc;
    n=5;
    acc=n;
    f=acc;
    acc-=1;

    while (true) {
        b=acc;
        acc=f;
        acc*=b;
        f=acc;
        acc=b;
        acc-=1;
        if (acc==0) break;
        acc=b;
        acc-=1;
    }
    cout << f;
}
