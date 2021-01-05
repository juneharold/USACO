// Sleepy cow sorting

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cows[100]={};
    // taking in input
    for (int i=0; i<N; i++)
    {
        cin >> cows[i];
    }
    //
    int counter=0;
    for (int j=0; j<N-1; j++)
    {
        if (cows[j]+1>cows[j+1])
        {
            counter=j+1;
        }
    }
    cout << counter;
}
