#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    int T=0, N3=8, N2=5;
    int P=(N3+N2)*N3;
    int N1;
    while (true) {
        N1=N3-N2;
        T=N3*N3+T;
        N3=N2;
        N2=N1;
        if (N1<=0) {
            break;
        }
    }
    cout << P-T;
}
