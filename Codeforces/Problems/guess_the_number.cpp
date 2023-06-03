#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int lo=1, hi=1e6;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        cout << mid << "\n";
        cout << flush; 
        string s; cin >> s;
        if (s=="<") {
            hi=mid-1;
        }
        else {
            lo=mid;
        }
    }
    cout << "! " << lo;
}
