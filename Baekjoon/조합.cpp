#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long

int main()
{
    ll N, R, ans=1; cin >> N >> R;
    for (int i=1; i<=N; i++) {
        ans*=i;
        ans%=MOD;
    }
    ll temp1=1;
    for (int i=1; i<=R; i++) {
        temp1*=i;
        temp1%=MOD;
    }
    for (int i=1; i<=N-R; i++) {
        temp1*=i;
        temp1%=MOD;
    }

    // Calculating temp1^(1e9+7-2)
    ll temp2=1;
    for (int i=1; i<=31622; i++) {
        temp2*=temp1;
        temp2%=MOD;
    }

    for (int i=1; i<=31622; i++) {
        ans*=temp2;
        ans%=MOD;
    }
    for (int i=1; i<=49121; i++) {
        ans*=temp1;
        ans%=MOD;
    }

    cout << ans;
}