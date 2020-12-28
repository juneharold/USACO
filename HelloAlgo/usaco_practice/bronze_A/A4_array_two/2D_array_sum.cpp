// 2차원 배열의 합
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // N is row, M is column
    int N, M;
    cin >> N >> M;
    // reading given array. 
    int array[90000] = {};
    for (int i=0; i<N*M; i++)
    {
        cin >> array[i];
    }
    int K;
    cin >> K;
    // reading (i, j), (x,y) positions
    int locations[40000] = {};
    for (int k=0; k<4*K; k++)
    {
        cin >> locations[k];
    }
    //
    for (int n=0; n<K; n++)
    {
        int i = locations[4*n], j = locations[4*n+1], x = locations[4*n+2], y = locations[4*n+3];
        // (i-1)*M+(j-1) this is the starting point
        // (x-1)*M+(y-1) this is ending point
        // (y-j) is width
        // (x-i) is height 
        int sum=0;
        // sum from (i-1)*M+(j-1) to (i-1)*M+(j-1) + (y-j)
        // then go from ((i-1)*M+(j-1))+M to ((i-1)*M+(j-1))+M + (y-j)
        for (int row=0; row<=(x-i); row++)
        {
            for (int col=0; col<=(y-j); col++)
            {
                sum += array[((i-1)*M+(j-1)) + row*M + col];
            }
        }
        printf("%d\n", sum);
    }
}
