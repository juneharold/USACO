#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int score[8]={}, order[8]={};
    for (int i=0; i<8; i++)
    {
        cin >> score[i];
        order[i] = i; //입력받은 순서를 나타냄. 
    }
    // bubble sort
    for (int a=0; a<8; a++)
    {
        for (int j=0; j<7; j++)
        {
            if (score[j]>score[j+1])
            {
                swap(score[j], score[j+1]);
                swap(order[j], order[j+1]);
            }
        }
    }
    // sum of last 5. 
    int sum=0;
    int order2[5]={};
    for (int p=3; p<8; p++)
    {
        sum += score[p];
        order2[p-3] = order[p];
    }
    cout << sum << endl;
    sort(order2, order2+5);
    for (int q=0; q<5; q++)
    {
        cout << order2[q]+1;
        cout << " ";
    }
}
