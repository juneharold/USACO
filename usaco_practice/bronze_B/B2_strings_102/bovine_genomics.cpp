// Bovine Genomics (Bronze)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    string spotty[100]={}, plain[100]={};
    for (int i=0; i<N; i++)
    {
        cin >> spotty[i];
    }
    for (int j=0; j<N; j++)
    {
        cin >> plain[j];
    }
    // going over M to see if they explain
    int counter = 0;
    for (int m=0; m<M; m++)
    {
        //see if each spotty is different to every plain at this column using double nested loop.
        int indicator=0;
        for (int a=0; a<N; a++)
        {
            for (int b=0; b<N; b++)
            {
                if (spotty[a][m] == plain[b][m])
                {
                    indicator=1;
                    break;
                }
            }
        }
        // if indicator==0 --> counter += 1
        if (indicator==0)
        {
            counter += 1;
        }
    }
    cout << counter << endl;
}
