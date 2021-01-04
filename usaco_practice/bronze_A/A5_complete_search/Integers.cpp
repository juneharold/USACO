// Are they all integers?
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[50]={};
    int indicator = 0;
    for (int input=0; input<N; input++)
    {
        cin >> A[input];
    }
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            for (int k=0; k<N; k++)
            {
                // the number: (A[i]-A[j])/A[k]
                if (i!=j and j!=k and k!=i and indicator==0)
                {
                    if (round((A[i]-A[j])/A[k])!=(A[i]-A[j])/A[k]) // this means that this is not int
                    {
                        cout << "no";
                        indicator = 1;
                    }
                }
            }
        }
    }
    if (indicator==0)
    {
        cout << "yes";
    }
}
