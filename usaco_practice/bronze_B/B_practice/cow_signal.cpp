// The cow signal
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int M, N, K;
    string signal[10] = {};
    for (int i=0; i<M; i++)
    {
        cin >> signal[i];
    }
    // double loop over signal[10]
    for (int a=0; a<M; a++)
    {
        for (int p=0; p<K; p++)
        {
            for (int b=0; b<N; b++)
            {
                // expand by K
                for (int j=0; j<K; j++)
                {
                    cout << signal[a][b];
                    if (j==K-1)
                    {
                        cout << endl;
                    }
                }
            }
        }
    }
}

