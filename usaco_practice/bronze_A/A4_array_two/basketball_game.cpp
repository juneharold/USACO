#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string players[150]={}; // making array for strings
    for (int i=0; i<N; i++)
    {
        cin >> players[i];
    }
    // sort array alphabetically
    sort(players, players+N);
    // find character>5
    int counter=0;
    string printed="";
    for (int i=0; i<N-4; i++)
    {
        if (players[i][0]==players[i+1][0] and players[i][0]==players[i+2][0] and players[i][0]==players[i+3][0] and players[i][0]==players[i+4][0])
        {
            int indicator=0;
            for (int j=0; j<printed.size(); j++)
            {
                if (players[i][0]==printed[j])
                {
                    indicator = 1;
                }
            }
            if (indicator!=1)
            {
                cout << players[i][0];
            }
            printed += players[i][0];
            counter += 1;
        }
    }
    //
    if (counter==0)
    {
        cout << "PREDAJA";
    }
}
