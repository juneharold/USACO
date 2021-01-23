#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    string cows[8]={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    sort(cows, cows+8);
    cin >> N;
    pair <string, string> beside[7]={};
    for (int i=0; i<N; i++)
    {
        string cow1, must, be, milked, besid, cow2;
        cin >> cow1 >> must >> be >> milked >> besid >> cow2;
        beside[i].first=cow1;
        beside[i].second=cow2;
    }
    do 
    {
        int sum=0;
        for (int i=0; i<7; i++)
        {
            for (int j=0; j<N; j++)
            {
                if ((cows[i]==beside[j].first or cows[i]==beside[j].second) and (cows[i+1]==beside[j].first or cows[i+1]==beside[j].second))
                {
                    sum += 1;
                }
            }
        }
        if (sum==N)
        {
            for (int i=0; i<8; i++)
            {
                cout << cows[i] << "\n";
            }
            return 0;
        }
    } while (next_permutation(cows, cows+8));
}
