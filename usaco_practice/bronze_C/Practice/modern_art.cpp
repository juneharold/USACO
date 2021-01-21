#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int N;
    cin >> N;
    int canvas[10][10]={}; //rows and columns
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            char a;
            cin >> a;
            canvas[i][j]=a-'0';
        }
    }
    // find the unique numbers
    int unique[10]={};
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int num = canvas[i][j];
            if (unique[num]==0 and num!=0)
            {
                unique[num]=1;
            }
        }
    }
    // main method
    int counter=0;
    int notpos[10]={};
    for (int a=1; a<10; a++)
    {
        int the_num;
        if (unique[a]!=0)
        {
            the_num=a;
        }
        else
        {
            continue;
        }
        int x1=10, y1=10, x2=0, y2=0;
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (canvas[i][j]==the_num)
                {
                    if (i<=y1)
                    {
                        y1=i;
                    }
                    if (j<=x1)
                    {
                        x1=j;
                    }
                    if (i>=y2)
                    {
                        y2=i;
                    }
                    if (j>=x2)
                    {
                        x2=j;
                    }
                }
            }
        }
        // now checking which numbers are impossible
        for (int i=y1; i<=y2; i++)
        {
            for (int j=x1; j<=x2; j++)
            {
                if (canvas[i][j]!=the_num)
                {
                    notpos[canvas[i][j]] = 1;
                }
            }
        }
    }
    // now we have notpos
    int Notpos=0;
    int Unique=0;
    for (int i=0; i<10; i++)
    {
        if (notpos[i]!=0 and i!=0)
        {
            Notpos += 1;
            //cout << "not" << i << "\n";
        }
        if (unique[i]!=0)
        {
            Unique += 1;
            //cout << "uni" << i << "\n";
        }
    }
    cout << Unique-Notpos;
}

/*
예제 1:
3
222
333
444
예제 2:
3
220
334
444
예제 3:
5
31340
31330
31330
01000
00000
예제 4:
3
042
353
142
*/
