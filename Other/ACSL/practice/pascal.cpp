#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
#define ll long long
#define f first
#define s second

ll row, coef, n, idx, ans;
ll pascal[205][205]={}, fib[205]={};
map<ll, ll> mp;

void move(ll i, ll j) {
    if (i<0 || j>=100) return;
    if (pascal[i][j]==0) return;
    mp[pascal[i][j]]++;
    move(i-1, j+1);
}

int main()
{
    cin >> n;

    fib[0]=1; fib[1]=1;
    for (ll i=2; i<=200; i++) {
        if (LLONG_MAX-fib[i-1]-fib[i-2]<0) {
            row=i;
            break;
        }
        fib[i]=fib[i-1]+fib[i-2];
    }

    for (ll i=0; i<=row; i++) {
        for (ll j=0; j<=i; j++) {
            if (j==0 || i==0) coef=1;
            else coef=coef*(i-j+1)/j;

            pascal[i][j]=coef;
        }
    }

    for (ll i=0; i<=200; i++) {
        if (fib[i]==n) {
            idx=i;
            break;
        }
    }

    for (ll i=0; i<=idx; i++) {
        move(i, 0);
    }

    for (auto x: mp) {
        if (x.s==1) ans++;
    }
    cout << ans;
}
