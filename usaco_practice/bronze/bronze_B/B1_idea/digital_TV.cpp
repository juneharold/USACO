// 디지털 티비 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string channel[100]={};
    for (int i=0; i<N; i++)
    {
        cin >> channel[i];
    }
    // check index of KBS1 and KBS2
    int kbs1_ind, kbs2_ind;
    for (int i=0; i<N; i++)
    {
        if (channel[i]=="KBS1")
        {
            kbs1_ind=i;
        }
        if (channel[i]=="KBS2")
        {
            kbs2_ind=i;
        }
    }
    string ans1="", ans2="";
    if (kbs1_ind<kbs2_ind)
    {
        for (int j=0; j<kbs2_ind; j++)
        {
            for (int i=0; i<N-1; i++)
            {
                if (i<kbs2_ind)
                {
                    swap(channel[i], channel[i+1]);
                    ans1 += "3";
                }
                else
                {
                    for (int k=0; k<=i; k++)
                    {
                        ans1 += "2";
                    }
                    break;
                }
                
            }
        }
    }
    else
    {
        for (int i=0; i<N-1; i++)
        {
            if (i<kbs1_ind)
            {
                swap(channel[i], channel[i+1]);
                ans1 += "3";
            }
        }
    }
    cout << ans1;
}