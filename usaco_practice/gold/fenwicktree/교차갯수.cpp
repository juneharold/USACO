#include <iostream>
#include <algorithm>
using namespace std;
#define f first
#define s second

const int N_MAX=2e3+5, M_MAX=N_MAX*N_MAX;
int N, M, fw[N_MAX]={};
pair<int, int> arr[M_MAX];

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
    cin >> N >> M;
    for (int i=0; i<M; i++) cin >> arr[i].f >> arr[i].s;
    sort(&arr[0], &arr[M]);

    long long ans=0;
    for (int i=M-1; i>=0; i--) {
        ans+=query(arr[i].s-1);
        update(arr[i].s, 1);
    }
    cout << ans;
}
