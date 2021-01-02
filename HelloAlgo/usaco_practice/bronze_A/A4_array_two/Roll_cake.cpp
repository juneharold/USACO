// 롤 케이크 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int L, N;
    cin >> L;
    cin >> N;
    int ranges[2000] = {};
    for (int i=0; i<2*N; i++)
    {
        cin >> ranges[i];
    }
    // number of cake
    int max_expected=0;
    int max_received=0;
    // number of person
    int num_ex=-1;
    int num_re=-1;
    int status[1000]={};
    for (int j=0; j<N; j++)
    {
        int start=ranges[2*j], end=ranges[2*j+1];
        // finding expectations
        int range = end-start+1;
        if (range>max_expected)
        {
            max_expected=range;
            num_ex=j+1;
        }
        // looping through the range
        int cake_received=0;
        for (int c=start; c<=end; c++)
        {
            if (status[c]==0)
            {
                cake_received += 1;
                status[c]=1;
            }
        }
        if (cake_received>max_received)
        {
            max_received=cake_received;
            num_re=j+1;
        }
    }
    cout << num_ex << endl;
    cout << num_re << endl;
}
