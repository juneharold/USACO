#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for (int i=1; i<=N; i++)
    {
        int g, x;
        cin >> g >> x;
        if (x-K<1) arr[1]+=g;
        else arr[x-K]+=g;
        if (x+K>1000004) arr[1000004]-=g;
        else arr[x+K+1]-=g;
    }
    int sum=0;
    int max=0;
    for (int i=1; i<=1000005; i++)
    {
        sum+=arr[i];
        if (sum>max)
        {
            max=sum;
        }
    }
    cout << max;
}


