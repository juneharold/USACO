// 그림 비교 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string painting[50]={};
    for (int i=0; i<N; i++)
    {
        string A, B, C, D, E, str;
        cin >> A >> B >> C >> D >> E;
        str = A+B+C+D+E;
        painting[i] = str;
    }
    // got all paintings...
    int max=0;
    int index1, index2;
    for (int p=0; p<N; p++)
    {
        for (int q=0; q<N && q!=p; q++)
        {
            int counter=0;
            string P=painting[p], Q=painting[q];
            for (int j=0; j<35; j++)
            {
                if (P[j]==Q[j])
                {
                    counter += 1;
                }
            }
            if (counter > max)
            {
                max=counter;
                index1=p;
                index2=q;
            }
        }
    }
    if (index1<index2)
    {
        cout << index1+1 << " " << index2+1 << endl;
    }
    else
    {
        cout << index2+1 << " " << index1+1 << endl;
    }
}
