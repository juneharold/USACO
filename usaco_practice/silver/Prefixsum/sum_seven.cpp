#include <iostream>
using namespace std;

long long PFS[100005]={};

int main()
{
    //freopen("div7.in", "r", stdin);
    //freopen("div7.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    long long sum=0;
    for (int i=1; i<=N; i++)
    {
        int a;
        cin >> a;
        sum += a;
        PFS[i]=sum%7;
    }
    int MAXcows=0;
    for (int i=0; i<=6; i++)
    {
        int from=50005, to=0;
        for (int j=1; j<=N; j++)
        {
            if (PFS[j]==i and j<from)
            {
                from=j;
            }
            if (PFS[j]==i and j>to)
            {
                to=j;
            }
        }
        if (to-from>MAXcows)
        {
            MAXcows=to-from;
        }
    }
    /*
    for (int i=1; i<=N; i++)
    {
        for (int j=i-MAXcows; j<=i; j++)
        {
            if (i-j<MAXcows)
            {
                break;
            }
            if ((PFS[i]-PFS[j-1])%7==0)
            {
                if (i-j>MAXcows)
                {
                    MAXcows=i-j;
                }
            }
        }
    }*/
    cout << MAXcows; 
}

/*
7
7
5
1
6
2
14
10
*/
