#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("milkorder.in", "r", stdin);
    //freopen("milkorder.out", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    pair <int, int> order[100]={};
    for (int i=0; i<M; i++)
    {
        cin >> order[i].first; //first is cow num, second is position
    }
    pair <int, int> fixpos[100]={}; //first-cow num, second-position
    for (int i=0; i<K; i++)
    {
        cin >> fixpos[i].first >> fixpos[i].second;
        for (int j=0; j<M; j++)
        {
            if (fixpos[i].first==order[j].first)
            {
                order[j].second=fixpos[i].second;
            }
        }
    }
    // first with fixed positions
    int line[105]={};
    for (int i=0; i<K; i++)
    {
        int position=fixpos[i].second, cow_num=fixpos[i].first;
        line[position-1]=cow_num;
    }
    // now find the first zero in array "line", then fill it with 
    for (int i=0; i<M; i++)
    {
        int cow_num=order[i].first;
        if (order[i].second!=0)
        {
            continue;
        }
        int aft=-1;
        int k_min=1;
        for (int j=i+1; j<M; j++)
        {
            if (order[j].second!=0)
            {
                aft=order[j].first;
                break;
            }
            k_min += 1;
        }
        //cout << k_min << "\n";
        if (aft==-1) //no hierarchy caows have fixed positions so we can just look for first 0.
        {
            break;
        }
        for (int j=0; j<105; j++)
        {
            if (line[j]==aft)
            {
                for (int k=k_min; k<100; k++)
                {
                    if (line[j-k]==0)
                    {
                        line[j-k]=cow_num;
                        break;
                    }
                }
                break;
            }
        }
    }
    // now find the first 1...
    int ans=-1, fir_zed=105;
    for (int i=0; i<105; i++)
    {
        if (line[i]==1)
        {
            ans=i;
            break;
        }
        if (line[i]==0 and i<=fir_zed)
        {
            fir_zed=i;
        }
    }
    if (ans==-1)
    {
        cout << fir_zed+1;
    }
    else
    {
        cout << ans+1;
    }
    /* print out line
    for (int i=0; i<10; i++)
    {
        cout << line[i];
    }*/
}
/* Test cases
6 3 2
4 5 6
5 3
3 1

8 4 3
4 5 6 7
6 4
3 2
7 6

3 2 1
2 1
2 2


*/
