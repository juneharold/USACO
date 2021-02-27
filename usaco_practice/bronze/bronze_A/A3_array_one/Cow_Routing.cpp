// cow routing
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    // declaring min_price
    int min_price=1001;
    // 
    for (int i=0; i<N; i++)
    {
        int price, num_cities;
        cin >> price >> num_cities;
        int cities[num_cities];
        for (int j=0; j<num_cities; j++)
        {
            cin >> cities[j];
        }
        // check if A and B in cities
        int counter=0;
        for (int k=0; k<num_cities; k++)
        {
            if (cities[k]==A and counter==0)
            {
                counter=1;
            } 
            if (cities[k]==B and counter==1)
            {
                counter=2;
            }
        }
        if (counter==2 and min_price > price) 
        {
            min_price=price;
        }
    }
    if (min_price==1001)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", min_price);
    }
}
