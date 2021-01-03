// 수빈이와 수열 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int sequence[N]; // this is sequence B
    for (int i=0; i<N; i++)
    {
        scanf("%d ", &sequence[i]);
    }
    printf("%d ", sequence[0]);
    for (int j=2; j<=N; j++)
    {
        printf("%d ", sequence[j-1]*j-sequence[j-2]*(j-1));
    }
}
