/*
ID: junehah1
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <algorithm>
using namespace std;

int milking_time[1000000]={};

int main()
{
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int start, end;
        cin >> start >> end;
        for (int j=start; j<end; j++)
        {
            milking_time[j]=1;
        }
    }
    // now count the longest 1s and 0s
    int cont=0, idle=0;
    int one_time=0, zero_time=0;
    int indicator=0;
    for (int i=0; i<1000000; i++)
    {
        if (milking_time[i]==1)
        {
            if (zero_time>idle)
            {
                idle=zero_time;
            }
            zero_time=0;
            one_time+=1;
            indicator=1;
        }
        if (milking_time[i]==0 and indicator==1)
        {
            if (one_time>cont)
            {
                cont = one_time;
            }
            one_time=0;
            zero_time+=1;
        }
    }
    cout << cont << " " << idle << "\n";
}
