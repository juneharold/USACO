// 성 지키기 
#include <iostream>
using namespace std;

int main()
{
    int N, M; // N은 세로 M은 가로 
    cin >> N >> M;
    int castle[1000][1000]={};
    for (int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            char a;
            cin >> a;
            if (a=='.')
            {
                castle[j][i]=0;
            }
            else
            {
                castle[j][i]=1;
            }// ascii code: 46-. 88-X
        }
    }
    // going over rows
    int counter_1=0;
    for (int i=0; i<N; i++)
    {
        int indicator=0;
        for(int j=0; j<M; j++)
        {
            if (castle[j][i]==1)
            {
                indicator=1;
            } // ascii code: 0-. 1-X
        }
        if (indicator==0)
        {
            counter_1 += 1;
        }
    }
    // going over colums
    int counter_2=0;
    for (int i=0; i<M; i++)
    {
        int indicator=0;
        for(int j=0; j<N; j++)
        {
            if (castle[i][j]==1)
            {
                indicator=1;
            } // ascii code: 46-. 1-X
        }
        if (indicator==0)
        {
            counter_2 += 1;
        }
    }
    if (counter_1>=counter_2)
    {
        cout << counter_1;
    }
    else
    {
        cout << counter_2;
    }
}
