#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int Bn[1000]={};
int An[1000]={};

int main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        if (i<N-1)
        {
            cin >> Bn[i];
        }
        An[i]=i+1; //index0=1
    }
    int sorted_until=0;
    do 
    {
        int indicator=0;
        for (int i=sorted_until; i<N-1; i++)
        {
            if (An[i]+An[i+1]!=Bn[i])
            {
                indicator=1;
                break;
            }
            sorted_until = i;
        }
        if (indicator==0)
        {
            for (int i=0; i<N; i++)
            {
                if (i<N-1)
                {
                    cout << An[i] << " ";
                }
                else
                {
                    cout << An[i] << "\n";
                }
            }
            return 0;
        }
    } while(next_permutation(&An[sorted_until-1], &An[N]));
}

/*
5
4 6 7 6
*/
