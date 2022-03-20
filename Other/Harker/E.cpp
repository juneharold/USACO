#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define ll long long
#define f first
#define s second

ll arr[1005][1005]={}, pfs[1005][1005]={};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll N; cin >> N;
    for (ll i=1; i<=N; i++) {
        char c; ll x1, y1, x2, y2, u;
        cin >> c >> x1>> y1 >> x2 >> y2 >> u;
        if (c=='B') u=-u;

        for (ll x=x1; x<x2; x++) {
            arr[x][y1]+=u;
            arr[x][y2+1]-=u;
        }
    }


    for (ll i=0; i<=1000; i++) {
        ll sum=0;
        for (ll j=0; j<=1000; j++) {
            sum+=arr[i][j];
            pfs[i][j]=sum;
        }
    }

    /*
    for (ll i=0; i<=20; i++) {
        for (ll j=0; j<=20; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
    for (ll i=0; i<=20; i++) {
        for (ll j=0; j<=20; j++) cout << pfs[i][j] << " ";
        cout << endl;
    }*/

    ll M=-1e9, cnt=0;
    for (ll i=0; i<1000; i++) {
        for (ll j=0; j<1000; j++) {
            M=max(M, pfs[i][j]);
        }
    }

    cout << M << " ";
    for (ll i=0; i<1000; i++) {
        for (ll j=0; j<1000; j++) {
            if (pfs[i][j]==M) cnt++;
        }
    }
    cout << cnt;
}

/*
3
B 1 1 4 4 5
B 1 3 7 5 3
B 3 0 6 4 9
*/
