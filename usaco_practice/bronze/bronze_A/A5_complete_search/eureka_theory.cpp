// 유레카 이론 
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    int eureka[46]={};
    for (int j=1; j<=45; j++)
    {
        eureka[j] = j*(j+1)/2;
    }
    int test_case;
    cin >> test_case;
    for (int i=0; i<test_case; i++)
    {
        int indicator=0;
        int input;
        cin >> input;
        for (int a=1; a<=45; a++)
        {
            for (int b=1; b<=45; b++)
            {
                for (int c=1; c<=45; c++)
                {
                    if (eureka[a]+eureka[b]+eureka[c]==input)
                    {
                        cout << 1 << endl;
                        indicator=1;
                        break;
                    }
                }
                if (indicator==1)
                {
                    break;
                }
            }
            if (indicator==1)
                {
                    break;
                }
        }
        if (indicator==0)
        {
            cout << 0 << endl;
        }
    }
}
