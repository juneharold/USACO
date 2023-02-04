#include <iostream>
using namespace std;

int func (int x) {
    if (x>=10) {
        return x+func(x-5);
    }
    else if (5<x && x<10) {
        return func(x+3)-4;
    }
    else if (x<=5) {
        return 2*x-1;
    }
}

int f2 (int x, int y) {
    if (x>y) {
        return f2(x-2, y+3)+3;
    }
    else if (x<y) {
        return f2(y-1, x+1)-5;
    }
    else if (x==y) {
        return x*y;
    }
}

int f3 (int x) {
    if (x==1) {
        return 1;
    }
    if (x>1) {
        return f3(x-1)+3*x-2;
    }
}

int f4(int x, int y) {
    if (x*y>=50) {
        return f4(x/2, y/2)+2;
    }
    else if (10<x*y && x*y<50) {
        return f4(2*x, y-3)+1;
    }
    else if (x*y<=10) {
        return x*y-x-y;
    }
}

void run_program(){
    int a=1, b=2, c=3, x=0;
    if (a<b) x=x+a;
    else x=x+b;

    if (b>c && a<=b) x=x+c;
    else x=x+a;

    if (!(a<b && a<c)) x=x+a;

    if (b<c || c<a) x=x+c;

    cout << x;
}

int main()
{
    //cout << f3(10);
    cout << f4(100, 36)-f4(36, 100);
    //cout << 7/2;
    //run_program();
}
