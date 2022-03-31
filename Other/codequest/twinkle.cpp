#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
#define PI 3.14159265

int main()
{
    int T; cin >> T;
    while (T--) {
        int xc, yc, p, r1, r2;
        cin >> xc >> yc >> p >> r1 >> r2;
        double angle=PI/2;
        for (int i=0; i<2*p; i++) {
            double x=cos(angle);
            if (i%2==0) x*=r1;
            else x*=r2;
            x+=xc;

            double y=sin(angle);
            if (i%2==0) y*=r1;
            else y*=r2;
            y+=yc;

            if (-0.005<=x && x<0) x=0.00;
            if (-0.005<=y && y<0) y=0.00;
            cout << fixed << setprecision(2) << x << "," << y << " ";
            angle+=2*PI/(p*2);
        }
        cout << "\n";
    }
}
