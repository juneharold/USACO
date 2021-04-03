#include <iostream>
#include <algorithm>
using namespace std;

int pos[50005]={};

int main()
{
    int L, N, M; cin >> L >> N >> M;
    for (int i=1; i<=N; i++) cin >> pos[i];
    pos[N+1]=L;
    sort(pos, pos+N+2);
    if (M==N)
    {
        cout << L;
        return 0;
    }
    int low=0, high=1e9;
    while (low<high)
    {
        int mid=(low+high)/2+1;
        int counter=0;
        for (int i=0; i<=N; i++) {
            int pos1=pos[i];
            int LB=lower_bound(&pos[0], &pos[N+1], pos1+mid)-&pos[0];
            counter+=LB-i-1;
            i=LB-1;
            }
        if (counter>M) high=mid-1;
        else low=mid;
    }
    cout << low;
}

/*
100 2 1
50
51
*/
