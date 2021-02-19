#include <iostream>
#include <algorithm>
using namespace std;

int Length[1000005]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    int low=0, high=1e9;
    for (int i=0; i<N; i++) 
    {
        cin >> Length[i];
        if (Length[i]>low) low=Length[i];
    }
    while (low<high)
    {
        int mid=(low+high)/2;
        int size_blr=mid;
        int num_blueray=0;
        for (int i=0; i<N; i++)
        {
            if (size_blr-Length[i]>=0)
            {
                size_blr-=Length[i];
            }
            else if (size_blr-Length[i]<0)
            {
                num_blueray++;
                size_blr=mid-Length[i];
            }
        }
        num_blueray++;
        //cout << mid << " " << num_blueray << "\n";
        if (num_blueray>M) low=mid+1;
        else high=mid;
    }
    cout << low;
}

/*
9 3
1 2 3 4 5 6 7 8 9

4 2
1 2 3 4

3 3 
4 6 10
*/
