#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int pfs[1000005]={};
int broken[1000005]={};

int main()
{
    //freopen("maxcross.in", "r", stdin);
    //freopen("maxcross.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, B;
    cin >> N >> K >> B;
    for (int i=0; i<B; i++)
    {
        int br;
        cin >> br;
        broken[br]=1;
    }
    int brcount=0;
    for (int i=1; i<=N; i++)
    {
        if (broken[i]==1)
        {
            brcount+=1;
        }
        pfs[i]=brcount;
    }
    int MIN=1e9;
    for (int i=1; i<=N-K+1; i++)
    {
        // i, i+K
        int lights=pfs[i+K-1]-pfs[i-1];
        if (lights<MIN)
        {
            MIN=lights;
        }
    }
    cout << MIN;
}

/*
10 6 0
*/
