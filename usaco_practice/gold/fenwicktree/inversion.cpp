#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const int MAX=1e6+5;
int N, fw[MAX]={};
pair<int, int> arr[MAX];

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
    for (int i=0; i<N; i++) {
        cin >> arr[i].f;
        arr[i].s=i+1;
    }
    sort(&arr[0], &arr[N]);
    long long ans=0;

    for (int i=N-1; i>=0; i--) {
        ans+=query(arr[i].s-1);
        update(arr[i].s, 1);
    }
    cout << ans;

}
