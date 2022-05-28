#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char color[5];
int hrs=0, mnt=0, sec=0, fib[5]={1, 1, 2, 3, 5};

int main()
{
    for (int i=0; i<5; i++) cin >> color[i];

    for (int i=0; i<5; i++) {
        if (color[i]=='W') continue;

        if (color[i]=='R') {
            hrs+=fib[i];
        }
        if (color[i]=='G') {
            mnt+=fib[i];
        }
        if (color[i]=='B') {
            sec+=fib[i];
        }
        if (color[i]=='Y') {
            hrs+=fib[i];
            mnt+=fib[i];
        }
        if (color[i]=='M') {
            hrs+=fib[i];
            sec+=fib[i];
        }
        if (color[i]=='C') {
            mnt+=fib[i];
            sec+=fib[i];
        }
    }

    sec*=5; mnt*=5;

    int second_carry=sec/60;
    sec%=60;

    mnt+=second_carry;
    int mnt_carry=mnt/60;
    mnt%=60;

    hrs+=mnt_carry;
    hrs%=12;

    if (hrs<10) cout << 0 << hrs << ":";
    else cout << hrs << ":";

    if (mnt<10) cout << 0 << mnt << ":";
    else cout << mnt << ":";

    if (sec<10) cout << 0 << sec;
    else cout << sec;
}
