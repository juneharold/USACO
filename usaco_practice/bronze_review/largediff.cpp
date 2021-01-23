#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[8]={};
    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int max=0;
    do 
    {
        int sum=0;
        for (int i=0; i<N-1; i++)
        {
            sum += abs(arr[i]-arr[i+1]);
        }
        if (sum >= max)
        {
            max = sum;
        }
    } while (next_permutation(arr, arr+N));

    cout << max;
    return 0;
}
