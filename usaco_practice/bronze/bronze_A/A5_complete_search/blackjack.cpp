// 블랙잭 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int cards[100];
    for (int i=0; i<N; i++)
    {
        cin >> cards[i];
    }
    // triple looping over the cards
    int max_sum=0;
    for (int a=0; a<N; a++)
    {
        for (int b=0; b<N; b++)
        {
            for (int c=0; c<N; c++)
            {
                if (a!=b and b!=c and c!=a)
                {
                    if (cards[a]+cards[b]+cards[c]>max_sum and cards[a]+cards[b]+cards[c]<=M)
                    {
                        max_sum = cards[a]+cards[b]+cards[c];
                    }
                }
            }
        }
    }
    cout << max_sum << endl;
}