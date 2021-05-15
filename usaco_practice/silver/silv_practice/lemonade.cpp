#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a>b;
}

int main()
{
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    int W[100005]={};
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> W[i];
    sort(W, W+n, cmp);
    int cow=0;
    for (int i=0; i<n; i++) {
        if (cow<=W[i]) {
            cow++;
        }
    }
    cout << cow;
}
