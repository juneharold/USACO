#include <iostream>
#include <algorithm>
using namespace std;

int a[1000005]={}, b[1000005]={};

int main()
{
    int N; cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];
    for (int i=1; i<=N; i++) cin >> b[i];

    int cnt=0;
    for (int i=1; i<N; i++) {
        if (a[i]==b[i]) continue;
        int x=(a[i]^b[i]);
        a[i]=x; 
        a[i+1]=(a[i+1]^x);
        cnt++;
    }

    if (a[N]==b[N]) cout << cnt;
    else cout << -1;
}