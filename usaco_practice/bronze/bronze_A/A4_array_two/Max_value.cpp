// 최댓값
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int numbers[81]={};
    for (int i=0; i<81; i++)
    {
        cin >> numbers[i];
    }
    // strategy: use mod %
    // finding max value
    int max=0, max_index=0;
    for (int j=0; j<81; j++)
    {
        if (numbers[j]>max)
        {
            max = numbers[j];
            max_index = j;
        }
    }
    printf("%d\n", max);
    printf("%d %d", (max_index-(max_index%9))/9+1, max_index%9+1);
}
