// Diamond Collector
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int diamonds[1000]={};
    for (int i=0; i<N; i++)
    {
        cin >> diamonds[i];
    }
    sort(diamonds, diamonds+N);
    int counter = 0;
    for (int j=0; j<N; j++)
    {
        for (int p=0; p<N; p++)
        {
            if (j>=p and diamonds[j]-diamonds[p]<=K)
            {
                if (j-p>counter)
                {
                counter = j-p+1;
                }
            }
        }
    }
    cout << counter << endl;
}
