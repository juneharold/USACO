#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int f(int x) {
    if(x>=10) return f(f(x-3))+3;
    else if (4<x && x<10) return f(x-2)-2;
    else return x-1;
}

string decToOctal(int n){
    int octalNum[100];
    int i = 0;
    while (n != 0) {
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
    string ret="";
    for (int j = i - 1; j >= 0; j--) {
        ret+=to_string(octalNum[j]);
    }
    return ret;
}

int main()
{
    int cnt=0;
    for (int i=2001; i<=2021; i++) {
        string oct=decToOctal(i);
        for (int i=0; i<oct.size(); i++) {
            if (oct[i]>'4') cnt++;
        }
    }
    cout << cnt;
}

/*
2
80
21
36
6
59
12
28
100
24
0
15
256
0
*/


/*
int main()
{
    int ans=0;
    for (int i=2000; i<=2199; i++) {
        string x=decToOctal(i);
        x+="AAAAAAA";

        for (int j=0; j<x.size(); j++) {
            if (x.substr(j, 2)=="41") {
                ans++;
            }
        }
    }
    cout << ans;
}*/
