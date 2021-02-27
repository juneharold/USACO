// FUNGHI
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int slices[11];
    for (int i=0; i<8; i++)
    {
        scanf("%d", &slices[i]);
    }
    // appending slices at index 0, 1, 2 at the back. 
    for (int k=0; k<3; k++)
    {
        slices[k+8] = slices[k];
    }
    // finding the max number of mushrooms
    int max=0;
    for (int j=0; j<8; j++)
    {
        if (slices[j]+slices[j+1]+slices[j+2]+slices[j+3] > max)
        {
            max = slices[j]+slices[j+1]+slices[j+2]+slices[j+3];
        }
    }
    printf("%d", max);
}
