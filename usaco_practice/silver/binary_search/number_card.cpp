#include <iostream>
#include <algorithm>
using namespace std;

long long have[1000000]={};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> have[i];
    }
    sort(have, have+N);
    cin >> M; 
    for (int i=1; i<=M; i++)
    {
        int low=0, high=N; 
        long long find;
        cin >> find;
        while (low<high)
        {
            int mid=(low+high)/2;
            if (have[mid]<find) low=mid+1;
            else high=mid;
        }
        if (have[low]==find) cout << 1 << " ";
        else cout << 0 << " ";
    }
}

