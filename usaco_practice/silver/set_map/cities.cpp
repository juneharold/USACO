#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

#define f first;
#define s second;

set <pair <string, string> > city_state;

int main()
{
    //freopen("citystate.in", "r", stdin);
    //freopen("citystate.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int i=0; i<N; i++)
    {
        string a, b; cin >> a >> b;
        city_state.insert(make_pair(a, b));
    }
    int counter=0;
    for (auto it=city_state.begin(); it!=(city_state.end()--); it++)
    {
        string city=(*it).f;
        string state=(*it).s;
        for (auto it2=it++; it2!=city_state.end(); it2++)
        {
            string city2=(*it2).f;
            string state2=(*it2).s;
            if (city[0]==state2[0] and city[1]==state2[1] and city2[0]==state[0] and city2[1]==state[1])
            {
                cout << city << state << "\n";
                cout << city2 << state2 << "\n";
                counter++;
            }
        }
    }
    cout << counter/2; 
}

/*
4
MIAMI MI
MICHIGAN MI
MIAMI FL
FLINT TX

6
MIAMI FL
DALLAS TX
FLINT MI
CLEMSON SC
BOSTON MA
ORLANDO FL
*/
