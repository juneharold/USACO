#include <iostream>
#include <algorithm>
using namespace std;

long long songtime[50005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    long long TIME=0;
    for (int i=1; i<=N; i++)
    {
        int B_i; cin >> B_i;
        songtime[i-1]=TIME;
        TIME+=B_i;
    }
    for (int i=0; i<Q; i++)
    {
        int a; cin >> a;
        int LB=lower_bound(&songtime[0], &songtime[N], a)-&songtime[0];
        if (LB==0) cout << 1 << "\n";
        else if (songtime[LB]==a) cout << LB+1 << "\n";
        else cout << LB << "\n";
    }
}

