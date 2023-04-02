#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

ll P[200005]={};

int main()
{
    int N; cin >> N;
    ll sum=0;
    for (int i=1; i<=N; i++) cin >> P[i];

    ll lo=1, hi=1e15;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        ll money=mid, cp10=0;
        for (int i=1; i<=N; i++) {
            if (money-P[i]>=0)  { // use money
                money-=P[i];
                cp10+=P[i];
            }
            else if (money>0 && P[i]>money) { //use money+cp
                ll price_left=P[i]-money;
                cp10-=price_left*10;
                if (cp10<0) cp10=-1e18;
                cp10+=money;
                money=0;
            }
            else { // use cashback point
                cp10-=P[i]*10;
            }
        }
        if (money>=0 && cp10>=0) hi=mid;
        else lo=mid+1;
    }
    cout << lo;
}

/*
1
100
*/