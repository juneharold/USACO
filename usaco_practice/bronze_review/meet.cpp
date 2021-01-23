#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int B, E;
    cin >> B >> E;
    pair <int, char> Bessie[50000] = {};
    pair <int, char> Elsie[50000] = {};
    for (int i=0; i<B; i++)
    {
        cin >> Bessie[i].first >> Bessie[i].second;
    }
    for (int i=0; i<E; i++)
    {
        cin >> Elsie[i].first >> Elsie[i].second;
    }
    int B_pos=0, E_pos=0;
    int E_fir=2; //
    int moo=0;
    for (int i=0; i<max(B, E); i++)
    {
        if (i<B)
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
        if (i<E)
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
        cout << B_pos << E_pos << "\n";
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
        if (og!=E_fir and og!=2 and i>0)
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
