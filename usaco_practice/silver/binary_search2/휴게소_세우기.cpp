#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int reststop[105]={};
    int N, M, L; cin >> N >> M >> L;
    for (int i=0; i<N; i++) cin >> reststop[i];
    sort(reststop, reststop+N);
    int low=1, high=1000;
    while(low<high)
    {
        int mid=(low+high)/2+1;
        int prev=0, counter=0;
        for (int i=0; i<N; i++)
        {
            if (reststop[i]-prev>mid)
            {
                int n=1;
                while(reststop[i]-prev>mid*n) n++;
                counter += n+1;
            }
            prev=reststop[i];
        }
        if (L-prev>mid)
        {
            int n=1;
            while(L-prev>mid*n) n++;
            counter += n+1;
        }
        if (counter<M) high=mid-1;
        else if (counter>M) low=mid;
    }
    cout << low;
}

