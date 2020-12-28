// 음계
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int sounds[8];
    for (int i=0; i<8; i++)
    {
        scanf("%d ", &sounds[i]);
    }
    int counter=0;
    for (int j=1; j<8; j++)
    {
        if (sounds[j-1] > sounds[j])
        {
            counter += 1;
        }
    }
    if (counter == 7)
    {
        printf("descending");
    }
    else if (counter == 0)
    {
        printf("ascending");
    }
    else
    {
        printf("mixed");
    }
}
