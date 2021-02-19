#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int reststop[105]={};
vector <int> difference;

int main()
{
    int N, M, L; cin >> N >> M >> L;
    for (int i=0; i<N; i++) cin >> reststop[i];
    sort(reststop, reststop+N);
    int prev=reststop[0];
    for (int i=1; i<N; i++)
    {
        int diff=reststop[i]-prev;
        difference.push_back(diff);
        prev=reststop[i];
    }
}


/*
int main()
{
    int N, M, L; cin >> N >> M >> L;
    for (int i=0; i<N; i++) cin >> reststop[i];
    sort(reststop, reststop+N);
    int low=1, high=1000;
    while(low<high)
    {
        int mid=(low+high)/2+1;
        int prev=0, counter=0;
        for (int i=1; i<N; i++)
        {
            if (reststop[i]-prev>mid)
            {
                int n=1;
                while(reststop[i]-prev>mid*n) n++;
                counter += n;
            }
            prev=reststop[i];
        }
        if (L-prev>mid)
        {
            int n=1;
            while(L-prev>mid*n) n++;
            counter += n;
        }
        if (counter<M) high=mid-1;
        else low=mid;
    }
    cout << low;
}
*/