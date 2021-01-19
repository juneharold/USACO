#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int N, M, D, S;
    cin >> N >> M >> D >> S;
    pair <int, pair<int, int> > TPM[1000]={}; //time, person, milk
    for (int i=0; i<D; i++)
    {
        // person, milk, time
        cin >> TPM[i].second.first >> TPM[i].second.second >> TPM[i].first;
    }
    pair <int, int> sick[50]={};
    for (int j=0; j<S; j++) //person, time
    {
        cin >> sick[j].first >> sick[j].second;
    }
    // find out which milk the sick people drank. --> sick.second
    // compare if the milk was drank before they got sick. 
    int possible_milk[1000]={};
    for (int i=0; i<S; i++)
    {
        int per=sick[i].first, time=sick[i].second;
        // go over PMT to see which milk per drank...
        for (int j=0; j<D; j++)
        {
            if (TPM[j].second.first==per)
            {
                if (TPM[j].first<time)
                {
                    possible_milk[j]=TPM[j].second.second;
                }
            }
        }
    }
    // for each milk, find out how many people drank... cout max drinker
    int max=0;
    for (int i=0; i<1000; i++)
    {
        int overlaps[50]={};
        int milk_drinker=0;
        int milk=possible_milk[i];
        for (int j=0; j<D; j++)
        {
            int indicator=0;
            // look for overlaps
            for (int k=0; k<50; k++)
            {
                if (TPM[j].second.first==overlaps[k])
                {
                    indicator=1;
                    break;
                }
            }
            if (TPM[j].second.second==milk and indicator==0)
            {
                milk_drinker+=1;
                overlaps[j] = TPM[j].second.first;
            }
        }
        if (milk_drinker>max)
        {
            max=milk_drinker;
        }
    }
    cout << max << "\n";
    return 0;
}