#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[1000]={};
    int odd=0, even=0;
    for (int i=0; i<N; i++)
    {
        int a;
        cin >> a;
        arr[i]=a;
        if (a%2==1)
        {
            odd+=1;
        }
        else
        {
            even+=1;
        }
    }
    int counter=0;
    int current=0; // 0 means even, 1 means odd
    while (even>=1 or odd >=1)
    {
        if (current==0)
        {
            if (even>=1)
            {
                even-=1;
                counter+=1;
            }
            else if (odd>=2)
            {
                odd-=2;
                counter+=1;
            }
            else
            {
                break;
            }
            current=1;
        }
        if (current==1)
        {
            if (odd>=1)
            {
                odd-=1;
                counter+=1;
            }
            else
            {
                break;
            }
            current=0;
        }
    }
    if (odd==1)
    {
        cout << counter-1;
    }
    else
    {
        cout << counter;
    }
}

