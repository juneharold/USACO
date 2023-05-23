#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MOD 1000000007
#define ll long long

ll fermat(int N, int R) {
    ll ret=1;
    for (int i=0; i<R; i++) {
        ret*=N-i;
        ret%=MOD;
    }
    ll R_fac=1;
    for (int i=1; i<=R; i++) {
        R_fac*=i;
        R_fac%=MOD;
    }
    // calculating R_fac^(1e9+7-2)
    ll temp=1, exponent=MOD-2; 
    while (exponent) {
        if (exponent%2) {
            temp*=R_fac;
            temp%=MOD;
        }
        R_fac*=R_fac;
        R_fac%=MOD;
        exponent/=2;
    }
    return (ret*temp)%MOD;
}

int main()
{
    ll n, a, b; cin >> n >> a >> b;
    // calculating 2^n - 1
    ll temp=1, nn=sqrt(n);
    for (int i=1; i<=nn; i++) {
        temp*=2;
        temp%=MOD;
    }
    ll ans=1;
    for (int i=1; i<=nn; i++) {
        ans*=temp;
        ans%=MOD;
    }
    for (int i=1; i<=n-nn*nn; i++) {
        ans*=2;
        ans%=MOD;
    }
    ans=(ans-1+MOD)%MOD;
    ans=(ans-fermat(n, a)+MOD)%MOD;
    ans=(ans-fermat(n, b)+MOD)%MOD;

    cout << (ans+MOD)%MOD;
}
