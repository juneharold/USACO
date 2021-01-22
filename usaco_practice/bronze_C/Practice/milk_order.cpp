#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int N, M, K;
    cin >> N >> M >> K;
    int order[100]={};
    int fix_pos_in_order[100]={};
    for (int i=0; i<M; i++)
    {
        cin >> order[i];
    }
    pair <int, int> fixpos[100]={}; //first-cow, second-position
    for (int i=0; i<K; i++)
    {
        cin >> fixpos[i].first >> fixpos[i].second;
        for (int j=0; j<M; j++)
        {
            if (fixpos[i].first==order[j])
            {
                fix_pos_in_order[j]=1;
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
        int cow_num=order[i];
        int bef=order[i+1];
        for (int j=0; j<105; j++)
        {
            // this is not to have the same number twice
            int indicate=0;
            for (int k=0; k<105; k++)
            {
                if (line[k]==cow_num)
                {
                    indicate=1;
                    break;
                }
            }
            if (indicate==0)
            {
                if (line[j]==bef)
                {
                    for (int k=1; k<100; k++)
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
    }
    // now find the first 0...
    int ans;
    for (int i=0; i<105; i++)
    {
        if (line[i]==0)
        {
            ans=i;
            break;
        }
    }
    cout << ans+1;
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

8 4 4
4 5 6 7
5 4
3 2
4 1
7 6

*/
