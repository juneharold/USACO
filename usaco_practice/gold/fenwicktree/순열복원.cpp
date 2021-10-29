#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const int MAX=1e6+5;
int N, fw[MAX]={}, arr[MAX];

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
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        update(i, 1);
    }

    int ans[MAX]={};
    for (int i=N; i>=1; i--) {
        int idx=i-arr[i], lo=1, hi=N;
        while (lo<hi) { //XXOOO
            int mid=(lo+hi)/2;
            if (query(mid)>=idx) hi=mid;
            else lo=mid+1;
        }
        ans[lo]=i;
        update(lo, -1);
    }

    for (int i=1; i<=N; i++) cout << ans[i] << " ";

}
