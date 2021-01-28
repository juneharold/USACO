#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

char FJ[100005]={};

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
        cin >> FJ[i];
    }
    char Bess1[3]={'H', 'P', 'S'};
    char Bess2[3]={'H', 'P', 'S'};
    int max=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            char first, second;
            first=Bess1[i];
            second=Bess2[j];
            for (int k=1; k<=N; k++)
            {
                int cut=k;
                int score=0;
                for (int q=1; q<=N; q++)
                {
                    if (q<=k) // first
                    {
                        if (Bess1[q]=='H' and FJ[q]=='S')
                        {
                            score += 1;
                        }
                        else if (Bess1[q]=='S' and FJ[q]=='P')
                        {
                            score += 1;
                        }
                        else if (Bess1[q]=='P' and FJ[q]=='H')
                        {
                            score += 1;
                        }
                    }
                    else
                    {
                        if (Bess1[q]=='H' and FJ[q]=='S')
                        {
                            score += 1;
                        }
                        else if (Bess1[q]=='S' and FJ[q]=='P')
                        {
                            score += 1;
                        }
                        else if (Bess1[q]=='P' and FJ[q]=='H')
                        {
                            score += 1;
                        }
                    }
                }
                if (score > max)
                {
                    max=score;
                }
            }
        }
    }
    cout << max;
}




