// BABBA
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int K;
    cin >> K;
    int A_count=1, B_count=0;
    for (int i=0; i<K; i++)
    {
        int b=B_count, a=A_count;
        B_count += a;
        A_count -= a;
        A_count += b;
    }
    printf("%d %d", A_count, B_count);
}
