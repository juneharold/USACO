#include <iostream>
#include <algorithm>
using namespace std;

pair <int, char> Bessie[1000000] = {};
pair <int, char> Elsie[1000000] = {};

int main()
{
    int B, E;
    cin >> B >> E;
    int indexB=0;
    for (int i=0; i<B; i++)
    {
        int time;
        char direction;
        cin >> time >> direction;
        for (int j=0; j<time; j++)
        {
            Bessie[indexB].first=1;
            Bessie[indexB].second=direction;
            indexB += 1;
        }
    }
    int indexE=0;
    for (int i=0; i<E; i++)
    {
        int time;
        char direction;
        cin >> time >> direction;
        for (int j=0; j<time; j++)
        {
            Elsie[indexE].first=1;
            Elsie[indexE].second=direction;
            indexE += 1;
        }
    }
    int B_pos=0, E_pos=0;
    int E_fir=2; //
    int moo=0;
    for (int i=0; i<max(indexB, indexE); i++)
    {
        if (i<indexB)
        {
            if (Bessie[i].second=='R')
            {
                B_pos += Bessie[i].first;
            }
            else if (Bessie[i].second=='L')
            {
                B_pos -= Bessie[i].first;
            }
        }
        if (i<indexE)
        {
            if (Elsie[i].second=='R')
            {
                E_pos += Elsie[i].first;
            }
            else if (Elsie[i].second=='L')
            {
                E_pos -= Elsie[i].first;
            }
        }
        //
        int og=E_fir;
        if (E_pos>B_pos)
        {
            E_fir=1;
        }
        else if (B_pos>E_pos)
        {
            E_fir=0;
        }
        else if (B_pos==E_pos)
        {
            E_fir=2;
        }
        // if og!=E_fir --> add 1
        // if og=2, E_fir=0or1
        if (og!=E_fir and og!=2 and i!=0)
        {
            moo += 1;
        }
    }
    cout << moo;
    return 0;
}

/*
5 5
3 L
5 R
1 L
2 R
4 R
3 L
5 R
1 L
2 R
4 R
*/
