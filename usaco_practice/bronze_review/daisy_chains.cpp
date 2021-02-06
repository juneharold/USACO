#include <iostream>
using namespace std;

int pfs[105]={};
int petals[105]={};

int main()
{
    int N;
    cin >> N;
    int sum=0;
    for (int i=1; i<=N; i++)
    {
        int a;
        cin >> a;
        sum += a;
        pfs[i]=sum;
    }
    for (int i=1; i<=N; i++)
    {
        for (int j=i; j<=N; j++)
        {
            double sum = pfs[i]-pfs[j-1];
            double avg = sum/(i-j+1);
            for (int k=i; k<=j; k++)
            {
                if ()
            }
        }
    }
}