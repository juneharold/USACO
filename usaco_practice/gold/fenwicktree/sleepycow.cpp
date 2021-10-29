#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAX=5e5+5;
int N, fw[MAX]={}, arr[MAX], K;

int query (int p) {
    int ret=0;
    while (p!=0) {
        ret+=fw[p];
        p-=(p&-p);
    }
    return ret;
}

void update(int p, int v) {
    while (p<=N) {
        fw[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];

    for (int i=N-1; i>=0; i--) {
        update(arr[i], 1);
        if (arr[i-1]>arr[i]) {
            K=i;
            break;
        }
    }
    cout << K << endl;

    for (int i=0; i<K; i++) {
        int between=K-i-1;
        cout << between+query(arr[i]-1) << " ";
        update(arr[i], 1);
    }
    return 0;
}
