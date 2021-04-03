#include <algorithm>
#include <iostream>
using namespace std;

int pfs[200005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    int sum=0;
    for (int i=0; i<N; i++)
    {
        int a; cin >> a;
        sum+=a;
        pfs[i]=sum;
    }
    for (int i=0; i<M; i++)
    {
        int T; cin >> T;
        int pos=upper_bound(&pfs[0], &pfs[N], T)-&pfs[0];
        cout << pos << "\n";
    }
}
