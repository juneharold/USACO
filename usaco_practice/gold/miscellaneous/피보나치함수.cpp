#include <iostream>
#include <algorithm>
using namespace std;

int ans0[41]={}, ans1[41]={};


int main()
{
    ans0[0]=1, ans1[0]=0;
    ans0[1]=0, ans1[1]=1;
    for (int i=2; i<=40; i++) {
        ans0[i]=ans0[i-1]+ans0[i-2], ans1[i]=ans1[i-1]+ans1[i-2];
    }
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        cout << ans0[N] << ' ' << ans1[N] << "\n";
    }
}