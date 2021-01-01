#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int array[30] = {};
    for (int i=0; i<30; i++)
    {
        int input;
        scanf("%d", &input);
        array[input-1] = 1;
    }
    // finding who didn't submit their work
    for (int i=0; i<30; i++)
    {
        if (array[i]==0)
        {
            cout << i+1 << endl;
        }
    }
}