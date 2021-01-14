#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arrival[100] = {}; // 수열 - 2n은 도착 시간, 2n+1은 검문 시간
    int time[100] = {};
    for (int i=0; i<N; i++)
    {
        cin >> arrival[i];
        cin >> time[i];
    }
    // bubble sort
    for (int a=0; a<N; a++)
    {
        for (int j=0; j<N-1; j++) // make sure that j<N-1
        {
            if (arrival[j]>arrival[j+1]) // compare arrival times.
            {
                // swap arrival and checking time
                swap(arrival[j], arrival[j+1]);
                swap((time[j]), time[j+1]);
            }
        }
    }
    // 
    int current=0;
    for (int t=0; t<N; t++)
    {
        if (current<arrival[t])
        {
            current = arrival[t];
        }
        current += time[t];
    }
    cout << current << endl;
}
