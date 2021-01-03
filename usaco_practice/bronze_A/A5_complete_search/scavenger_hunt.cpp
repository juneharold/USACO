/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int p, q;
    cin >> p >> q;
    int p_array[6000]={}, q_array[6001]={};
    // finding the factors
    for (int i=1; i<6000; i++)
    {
        if (p%i==0)
        {
            p_array[i] = 1;
        }
        if (q%i==0)
        {
            q_array[i] = 1;
        }
    }
    // printing out using nested for loop
    for (int j=1; j<6000; j++)
    {
        if (p_array[j]==1)
        {
            for (int k=0; k<6000; k++)
            {
                if (q_array[k]==1)
                {
                    printf("%d %d\n", j, k);
                }
            }
        }
    }
}
