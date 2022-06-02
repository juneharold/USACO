#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int arr[100005]={};
map<int, int> primes;

int f(int x) {
    if(x%2==1 && primes[x]==1) return f(x-2)+1;
    else if (x%2==0) return f(x/2)+3;
    else return x+1;
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

string decToHexa(int n)
{
    char hexaDeciNum[100];
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    string ret;
    for (int j = i - 1; j >= 0; j--)
        ret+=hexaDeciNum[j];
    return ret;
}

int p[100]={};

int main()
{
    /*
    for (int i=2; i<=10000; i++) arr[i]=i;

    for (int i=2; i<=10000; i++) {
        if (arr[i]!=0) {
            int from=i*i;
            for (int j=from; j<=10000; j+=i) arr[j]=0;
        }
    }
    for (int i=2; i<=10000; i++) if(arr[i]!=0) primes[i]=1;

    cout << f(f(f(f(20))));*/

    int cnt=0, fib[20]={};
    fib[0]=0; fib[1]=1;
    for (int i=2; i<=19; i++) fib[i]=fib[i-1]+fib[i-2];
    for (int x=3; x<=6; x++) {
        int f=fib[x];
        for (int y=x+1; y<=19; y++) {
            if (fib[y]%f==0) cnt++;
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
