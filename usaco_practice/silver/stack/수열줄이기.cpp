#include <iostream>
#include <algorithm>
using namespace std;
long long N, ans=0, a[1000005]={};

int main()
{
    cin >> N;
    for (int i=1; i<=N; i++) cin >> a[i];

    for (int i=1; i<=N-1; i++) {
        ans+=max(a[i], a[i+1]);
    }
    cout << ans;
}

/*
8
1 3 4 2 3 1 5 8
*/
