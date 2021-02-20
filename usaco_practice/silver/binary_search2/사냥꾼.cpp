#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int shooter[100005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N, L; cin >> M >> N >> L;
    for (int i=0; i<M; i++) cin >> shooter[i];
    sort(shooter, shooter+M);
    int counter=0;
    for (int i=0; i<N; i++) 
    {
        int x, y; cin >> x >> y;
        int LB=lower_bound(&shooter[0], &shooter[M], x)-&shooter[0];
        int UB=upper_bound(&shooter[0], &shooter[M], x)-&shooter[0];
        if (UB==M or LB==M) 
        {
            int distance=abs(shooter[M-1]-x)+y;
            if (distance<=L) counter++;
            continue;
        }
        if (shooter[LB]==0 or shooter[UB-1]==0)
        {
            int distance=abs(shooter[0]-x)+y;
            if (distance<=L) counter++;
            continue;
        }
        if (abs(shooter[LB]-x)<=abs(shooter[UB-1]-x))
        {
            int distance=abs(x-shooter[LB])+y;
            if (distance<=L) counter++;
        }
        else 
        {
            int distance=abs(x-shooter[UB-1])+y;
            if (distance<=L) counter++;
        }
    }
    cout << counter;
}

/*
4 8 4
6 1 4 9
7 2
3 3
4 5
5 1
2 2
1 4
8 4
9 4
*/