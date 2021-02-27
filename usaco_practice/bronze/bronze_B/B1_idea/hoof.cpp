// Hoof, Paper, Scissors
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cow_A[100]={}, cow_B[100]={};
    for (int i=0; i<N; i++)
    {
        cin >> cow_A[i] >> cow_B[i];
    }
    // let's say 1>2, 2>3, 3>1 smaller wins
    int counter_1=0;
    for (int i=0; i<N; i++)
    {
        int A=cow_A[i], B=cow_B[i];
        if (A==3 and B==1)
        {
            counter_1+=1;
        }
        else if (A<B and (B-1==A))
        {
            counter_1+=1;
        }
    }
    // let's say 1<2, 2<3, 3<1 larger wins
    int counter_2=0;
    for (int j=0; j<N; j++)
    {
        int A=cow_A[j], B=cow_B[j];
        if (A==1 and B==3)
        {
            counter_2+=1;
        }
        else if (A>B and (A-1==B))
        {
            counter_2+=1;
        }
    }
    // printing larger
    if (counter_1>=counter_2)
    {
        cout << counter_1 << endl;
    }
    else
    {
        cout << counter_2 << endl;
    }
}
