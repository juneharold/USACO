#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long

double a[100005]={};
int b1[100005]={}, b2[100005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=N; i++) {
        b1[i]=(int)ceil(a[i]);
        b2[i]=(int)floor(a[i]);
    }

    ll sum=0;
    for (int i=1; i<=N; i++) {
        sum+=b1[i];
    }
    int i=1;
    while (i<=N) {
        if (sum && b1[i]>b2[i]) {
            cout << b2[i] << "\n";
            sum--;
        }
        else {
            cout << b1[i] << "\n";
        }
        i++;
    }
}

/*
5
-6.32509
3.0000
-0.93878
2.00000
1.96321
*/
