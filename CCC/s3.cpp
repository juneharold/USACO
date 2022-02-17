#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <map>
using namespace std;
#define f first
#define s second
#define ll long long

ll N, M, K;

int main()
{
    cin >> N >> M >> K;
    if (K<N || K>2*N-1) {
        cout << "-1";
        exit(0);
    }
    ll b=K-N;
    ll a=N-b;

    for (ll i=1; i<=a; i++) {
        cout << "1 ";
    }

    ll prev=1;
    for (ll i=a+1; i<=a+b; i++) {
        if (prev==1) {
            cout << "2 ";
            prev=2;
        }
        else {
            cout << "1 ";
            prev=1;
        }
    }
}
