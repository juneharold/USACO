#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char FJ[100005]={};
char A[3][100005]={};

int main()
{
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        char a;
        cin >> a;
        if (a=='H') A[0][i]++;
        if (a=='P') A[1][i]++;
    }
}




