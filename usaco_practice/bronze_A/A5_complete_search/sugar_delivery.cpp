// 설탕 배달 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max_three=n/3+1, max_five=n/5+1;
    int num_bags=max_five+max_three;
    // five first
    for (int i=0; i<max_five; i++)
    {
        for (int j=0; j<max_three+1; j++)
        {
            if (n==5*i+3*j)
            {
                if (i+j<=num_bags)
                {
                    num_bags=i+j;
                }
            }
        }
    }
    if (num_bags==max_five+max_three)
    {
        cout << -1;
    }
    else
    {
        cout << num_bags;
    }
}
