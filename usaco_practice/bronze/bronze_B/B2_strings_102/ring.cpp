// 반지

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int strlen = str.size();
    int N;
    cin >> N;
    int counter = 0;
    for (int i=0; i<N; i++)
    {
        string ring;
        cin >> ring;
        ring = ring + ring;
        for (int j=0; j<ring.size()-strlen; j++)
        {
            string new_ring = ring.substr(j, strlen);
            if (new_ring==str)
            {
                counter += 1;
                break;
            }
        }
    }
    cout << counter;
}