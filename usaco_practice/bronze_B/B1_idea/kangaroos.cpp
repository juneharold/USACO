// 캥거루 세마리 

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (C-B>=B-A)
    {
        cout << C-B-1;
    }
    else
    {
        cout << B-A-1;
    }
}