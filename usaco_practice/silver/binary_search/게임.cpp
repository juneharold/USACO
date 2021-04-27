#include <iostream>
using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;
    long long high=1000000000, low=0;
    long long og=((float)Y/X)*100;
    //cout << og;
    while (high>low) {
        long long mid=(high+low)/2;
        long long Z=((float)(Y+mid)/(X+mid))*100;
        if (Z==99) {
            cout << -1;
            exit(0);
        }
        if (Z>og) high=mid;
        else low=mid+1;
    }
    cout << low;
}
