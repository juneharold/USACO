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
                int num=(A[i]-A[j])/A[k];
                double num2=(A[i]-A[j])/A[k] + (A[i]-A[j])%A[k];
                if (i!=j and j!=k and k!=i)
                {
                    if (num!=num2) // this means that this is not int
                    {
                        cout << "no";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "yes";
    return 0;
}
