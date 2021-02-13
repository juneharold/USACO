#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long N, M;
    cin >> N >> M;
    long long trees[1000005]={};
    long high=1e9, low=0;
    for (int i=0; i<N; i++) 
    {
        cin >> trees[i];
    }
    while(low<high)
    {
        long long mid=(low+high+1)/2;
        long long sum=0;
        for (int i=0; i<N; i++)
        {
            if (trees[i]>mid)
            {
                sum += trees[i]-mid;
            }
        }
        if (sum<M) high=mid-1;
        else low=mid;
    }
    cout << low;
}

