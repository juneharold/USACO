// dna-sequencing

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int M, F; //M is bull, F is cow
    cin >> M >> F;
    string bulls[20]={}, cows[20]={};
    for (int i=0; i<M; i++)
    {
        cin >> bulls[i];
    }
    for (int j=0; j<F; j++)
    {
        cin >> cows[j];
    }
    // double loop over... 
    for (int a=0; a<M; a++)
    {
        for (int b=0; b<F; b++)
        {
            int counter=0;
            string cow=cows[b], bull=bulls[a];
            // loop again
            for (int p=0; p<F; p++)
            {
                if (p!=b) // edge case: bull and cow parent could have same genome sequence.
                {
                    int indicator=0;
                    for (int k=0; k<25; k++)
                    {
                        if (cows[p][k]==cow[k] or cows[p][k]==bull[k])
                        {
                            indicator += 1;
                        }
                    }
                    if (indicator==25)
                    {
                        counter += 1;
                    }
                }
            }
            for (int q=0; q<M; q++)
            {
                if (q!=a)
                {
                    int indicator=0;
                    for (int k=0; k<25; k++)
                    {
                        if (bulls[q][k]==cow[k] or bulls[q][k]==bull[k])
                        {
                            indicator += 1;
                        }
                    }
                    if (indicator==25)
                    {
                        counter += 1;
                    }
                }
            }
            cout << counter << " ";
        }
        cout << endl;
    }
}
