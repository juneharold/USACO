// Missing Numbers
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int runners[N-1];
    for (int i=0; i<N-1; i++)
    {
        cin >> runners[i];
    }
    // finding the sum of 1 to N
    int sum=0;
    for (int j=1; j<=N; j++)
    {
        sum += j;
    }
    // finding the sum of elements in runners array
    int sum_r=0;
    for (int k=0; k<N-1; k++)
    {
        sum_r += runners[k];
    }
    // sum - sum_r == missing runner
    printf("%d", sum-sum_r);
}
