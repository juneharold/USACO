// Mixing milk
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;
    for (int i=1; i<=33; i++)
    {
        // operation from c1 to c2
        if (c2-m2>=m1)
        {
            m2 += m1;
            m1 = 0;
        }
        else
        {
            m1 -= (c2-m2);
            m2 = c2;
        }
        // operation from c2 to c3
        if (c3-m3>=m2)
        {
            m3 += m2;
            m2 = 0;
        }
        else
        {
            m2 -= (c3-m3);
            m3 = c3;
        }
        // operation from c3 to c1
        if (c1-m1>=m3)
        {
            m1 += m3;
            m3 = 0;
        }
        else
        {
            m3 -= (c1-m1);
            m1 = c1;
        }
    }
    // the hundreth operation
    if (c2-m2>=m1)
    {
        m2 += m1;
        m1 = 0;
    }
    else
    {
        m1 -= (c2-m2);
        m2 = c2;
    }
    // printing answersss
    printf("%d\n", m1);
    printf("%d\n", m2);
    printf("%d\n", m3);
}

