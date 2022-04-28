#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        char temp;
        double v, x; cin >> v >> temp >> x;
        double time=x/v;
        if (time<=1) cout << "SWERVE\n";
        else if (time<=5) cout << "BRAKE\n";
        else cout << "SAFE\n";
    }
}
/*
5
23.15:98.34
2.40:17.33
6.79:5.01
0.00:1.53
113.56:113.56
*/
