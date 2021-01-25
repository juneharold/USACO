#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long cows[20]={};
    long barns[20]={};
    for (int i=0; i<N; i++)
    {
        cin >> cows[i];
    }
    for (int i=0; i<N; i++)
    {
        cin >> barns[i];
    }
    // find how many cows can fit into each barn. 
    int fit[20]={};
    for (int i=0; i<N; i++)
    {
        int fitcows=0;
        for (int j=0; j<N; j++)
        {
            if (barns[i]>=cows[j])
            {
                fitcows+=1;
            }
        }
        fit[i]=fitcows;
    }
    sort(fit, fit+N);
    int subtract=0;
    long long counter=1;
    for (int i=0; i<N; i++)
    {
        int num=fit[i]-subtract;
        counter = counter*num;
        subtract += 1;
    }
    /* do while next permutations
    do 
    {
        int indicator=0;
        for (int i=0; i<N; i++)
        {
            if (cows[i]>barns[i])
            {
                indicator=1;
                break;
            }
        }
        if (indicator==0)
        {
            counter += 1;
        }
    } while (next_permutation(cows, cows+N));*/
    cout << counter;
}

/*
4
1 2 3 4
2 4 3 4

4
1 2 3 4
2 4 2 4

12 
1 2 3 4 5 6 7 8 9 9
1 2 3 4 5 6 7 8 9 10
*/
