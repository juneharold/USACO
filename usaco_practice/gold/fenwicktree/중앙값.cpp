#include <iostream>
#include <algorithm>
using namespace std;

int N, K, fw[65538]={}, arr[250005];

int query (int p) {
    int ret=0;
    while (p!=0) {
        ret+=fw[p];
        p-=(p&-p);
    }
    return ret;
}

void update(int p, int v) {
    while (p<=65536) {
        fw[p]+=v;
        p+=(p&-p);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    long long ans=0;
    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        arr[i]+=1;
        update(arr[i], 1);
        if (K<=i) {
            int target=(K+1)/2, lo=1, hi=65537;
            while(lo<hi) {
                int mid=(lo+hi)/2;
                if (query(mid)>=target) hi=mid;
                else lo=mid+1;
            }
            ans+=lo-1;
            update(arr[i-K+1], -1);
        }
    }
    cout << ans;
}
