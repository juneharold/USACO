#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    //freopen("cowtip.in", "r", stdin);
    //freopen("cowtip.out", "w", stdout);
    int N;
    cin >> N;
    int arr[10][10]={}; //arr[rows][columns]
    for (int i=0; i<N; i++) //the numbers are stuck next to each other.... fuck
    {
        for (int j=0; j<N; j++)
        {
            char a;
            cin >> a;
            arr[i][j] = a - '0';
        }
    }
    // bottom up
    int r=-1,c=-1;
    int counter = 0;
    while (true)
    {
        //find bottom 1
        for (int m=0; m<N; m++)
        {
            for (int n=0; n<N; n++)
            {
                if (arr[m][n]==1)
                {
                    r=m;
                    c=n;
                }
            }
        }
        if (r==-1 and c==-1)
        {
            break;
        }
        // change all 
        for (int p=0; p<N; p++)
        {
            for (int q=0; q<N; q++)
            {
                if (p<=r and q<=c)
                {
                    if (arr[p][q]==1)
                    {
                        arr[p][q]=0;
                    }
                    else if (arr[p][q]==0)
                    {
                        arr[p][q]=1;
                    }
                    
                }
            }
        }
        // add 1 to counter
        counter += 1;
        r=-1;
        c=-1;
    }
    cout << counter << "\n";
}
