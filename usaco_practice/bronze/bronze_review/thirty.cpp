#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string N;
    cin >> N;
    int len=N.size();
    int digit[100000]={};
    int digit_sum=0;
    for (int i=0; i<len; i++)
    {
        int a=N[i]-'0';
        digit_sum += a;
        digit[i]=a;
    }
    sort(N.begin(), N.end());
    if (digit_sum%3==0)
    {
        int indicate=0;
        if (N[0]=='0')
        {
            for (int i=len-1; i>=0; i--)
            {
                cout << N[i];
            }
        }
        else
        {
            cout << "-1";
        }
    }
    else
    {
        cout << "-1";
    }
} 
